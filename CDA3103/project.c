#include "spimcore.h"

void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero) {   
    switch(ALUControl) {
        // addition
        case 0:
            *ALUresult = (A + B);
            break;

        // subtraction
        case 1:
            *ALUresult = (int)A - (int)B;
            break;

        // set on less than
        case 2:
            *ALUresult = (int)A < (int)B;
            break;

        // set on less than unsigned
        case 3:
            *ALUresult = A < B;
            break;

        // bitwise AND
        case 4:
            *ALUresult = A & B;
            break;

        // bitwise OR
        case 5:
            *ALUresult = A | B;
            break;

        // left shift by 16
        case 6:
            *ALUresult = B << 16;
            break;

        // bitwise NOT
        case 7:
            *ALUresult = ~A;
            break;
    }

    *Zero = *ALUresult == 0;
}

int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction) {
    // halt if address is not word-aligned
    if (PC % 4 != 0) return 1;

    // halt if address is beyond memory
    if (PC >= 65536) return 1;

    *instruction = MEM(PC);

    // halt if instruction is illegal
    return *instruction == 0;
}

void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec) {
    *op     = (instruction >> 26) & 0x3F;
    *r1     = (instruction >> 21) & 0x1F;
    *r2     = (instruction >> 16) & 0x1F;
    *r3     = (instruction >> 11) & 0x1F;
    *funct  = instruction & 0x3F;
    *offset = instruction & 0xFFFF;
    *jsec   = instruction & 0x03FFFFFF;
}

int instruction_decode(unsigned op, struct_controls *controls) {
    switch (op) {
        // R-Type
        case 0x00:
	        controls->RegDst = 1;
	        controls->Jump = 0;
	        controls->Branch = 0;
	        controls->MemRead = 0;
	        controls->MemtoReg = 0;
	        controls->ALUOp = 7;
	        controls->MemWrite = 0;
	        controls->ALUSrc = 0;
	        controls->RegWrite = 1;
            break;

        // add immediate
        case 0x08:
	        controls->RegDst = 0;
	        controls->Jump = 0;
	        controls->Branch = 0;
	        controls->MemRead = 0;
	        controls->MemtoReg = 0;
	        controls->ALUOp = 0b00;
	        controls->MemWrite = 0;
	        controls->ALUSrc = 1;
	        controls->RegWrite = 1;
            break;

        // set on less than immediate
        case 0x0A:
	        controls->RegDst = 0;
	        controls->Jump = 0;
	        controls->Branch = 0;
	        controls->MemRead = 0;
	        controls->MemtoReg = 0;
	        controls->ALUOp = 2;
	        controls->MemWrite = 0;
	        controls->ALUSrc = 1;
	        controls->RegWrite = 1;
            break;

        // set on less than unsigned immediate
        case 0x0B:
	        controls->RegDst = 0;
	        controls->Jump = 0;
	        controls->Branch = 0;
	        controls->MemRead = 0;
	        controls->MemtoReg = 0;
	        controls->ALUOp = 3;
	        controls->MemWrite = 0;
	        controls->ALUSrc = 1;
	        controls->RegWrite = 1;
            break;

        // load word
        case 0x23:
	        controls->RegDst = 0;
	        controls->Jump = 0;
	        controls->Branch = 0;
	        controls->MemRead = 1;
	        controls->MemtoReg = 1;
	        controls->ALUOp = 0;
	        controls->MemWrite = 0;
	        controls->ALUSrc = 1;
	        controls->RegWrite = 1;
            break;

        // store word
        case 0x2B:
	        controls->RegDst = 2;
	        controls->Jump = 0;
	        controls->Branch = 0;
	        controls->MemRead = 0;
	        controls->MemtoReg = 2;
	        controls->ALUOp = 0;
	        controls->MemWrite = 1;
	        controls->ALUSrc = 1;
	        controls->RegWrite = 0;
            break;

        // branch if equal
        case 0x04:
	        controls->RegDst = 2;
	        controls->Jump = 0;
	        controls->Branch = 1;
	        controls->MemRead = 0;
	        controls->MemtoReg = 2;
	        controls->ALUOp = 1;
	        controls->MemWrite = 0;
	        controls->ALUSrc = 0;
	        controls->RegWrite = 0;
            break;

        // jump
        case 0x02:
	        controls->RegDst = 2;
	        controls->Jump = 1;
	        controls->Branch = 0;
	        controls->MemRead = 0;
	        controls->MemtoReg = 2;
	        controls->ALUOp = 8;
	        controls->MemWrite = 0;
	        controls->ALUSrc = 2;
	        controls->RegWrite = 0;
            break;
        default:
            return 1;
    }

    return 0;
}

void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2) {
    *data1 = Reg[r1];
    *data2 = Reg[r2];
}

void sign_extend(unsigned offset,unsigned *extended_value) {
    *extended_value = (offset & 0x00008000) ? (0xFFFF0000 | offset) : offset;
}

int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero) {
    unsigned ALUControl;

    switch (ALUOp) {
        case 7:
            switch (funct) {
                // addition
                case 0x02: ALUControl = 0; break;
                // subtraction
                case 0x22: ALUControl = 1; break;
                // and
                case 0x24: ALUControl = 4; break;
                // or
                case 0x25: ALUControl = 5; break;
                // set on less than
                case 0x2A: ALUControl = 2; break;
                // set on less than unsigned
                case 0x29: ALUControl = 3; break;
                default: return 1;
            }
        case 8: return 0;
        default: ALUControl = ALUOp; break;
    }

    ALU(data1, ALUSrc ? extended_value : data2, ALUControl, ALUresult, Zero);

    return 0;
}

int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem) {
    if (!MemRead && !MemWrite) return 0;

    // halt if address is not word-aligned
    if (ALUresult % 4 != 0) return 1;

    // halt if address is beyond memory
    if (ALUresult >= 65536) return 1;

    if (MemRead) *memdata = MEM(ALUresult);

    if (MemWrite) MEM(ALUresult) = data2;

    return 0;
}

void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg) {
    if (RegWrite)
        Reg[(RegDst ? r3 : r2)] = MemtoReg ? memdata : ALUresult;
}

void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC) {
    *PC += 4;

    if (Jump)
        *PC = (*PC & 0xF0000000) | (jsec << 2);
    else if (Zero && Branch)
        *PC += extended_value << 2;
}