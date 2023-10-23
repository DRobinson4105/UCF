/*============================================================================
| Assignment: pa02 - Calculating an 8, 16, or 32 bit
| checksum on an ASCII input file
|
| Author: David Robinson
| Language: Java
|
| To Compile: javac pa01.java
|
| To Execute: java -> java pa01 kX.txt pX.txt
|
| Note: All input files are simple 8 bit ASCII input
|
| Class: CIS3360 - Security in Computing - Fall 2023
| Instructor: McAlpin
| Due Date: 11/12/2023
+===========================================================================*/

import java.util.Scanner;
import java.util.NoSuchElementException;
import java.io.File;
import java.io.FileNotFoundException;

public class pa02 {
    private static String convertToHex(int num) {
        if (num < 16)
            return "0" + Integer.toHexString(num);
        else
            return Integer.toHexString(num);
    }

    private static String computeChecksum8(String message) {
        int res = 0;

        for (int i = 0; i < message.length(); i++) {
            res = (res + message.charAt(i)) % 256;
        }

        return Integer.toHexString(res);
    }

    private static String computeChecksum16(String message) {
        int res1 = 0;
        int res2 = 0;
        int carry = 0;
        int tmp;

        for (int i = 0; i < message.length(); i += 2) {
            tmp = res2 + message.charAt(i + 1);
            res2 = tmp % 256;
            carry = tmp / 256;
            if (carry < 0) carry = 0;

            res1 = (res1 + message.charAt(i) + carry) % 256;
        }

        return Integer.toHexString(res1) + convertToHex(res2);
    }

    private static String computeChecksum32(String message) {
        int res1 = 0;
        int res2 = 0;
        int res3 = 0;
        int res4 = 0;
        int carry = 0;
        int tmp;

        for (int i = 0; i < message.length(); i += 4) {
            tmp = res4 + message.charAt(i + 3);
            res4 = tmp % 256;
            carry = tmp / 256;
            if (carry < 0) carry = 0;

            tmp = res3 + message.charAt(i + 2) + carry;
            res3 = tmp % 256;
            carry = tmp / 256;
            if (carry < 0) carry = 0;

            tmp = res2 + message.charAt(i + 1) + carry;
            res2 = tmp % 256;
            carry = tmp / 256;
            if (carry < 0) carry = 0;

            res1 = (res1 + message.charAt(i) + carry) % 256;
        }

        return Integer.toHexString(res1) + convertToHex(res2) + convertToHex(res3) + convertToHex(res4);
    }

    public static void main(String[] args) throws FileNotFoundException {
        File messageFile = new File(args[0]);
        Scanner messageScanner = new Scanner(messageFile);
        int checksumSize = Integer.parseInt(args[1]);
        System.out.println();

        // get message from file
        String message = "";
        while (true) {
            try {
                message += messageScanner.nextLine();
            } catch (NoSuchElementException e) {
                break;
            }
        }

        message += "\n";

        // pad message
        if (checksumSize == 8 || checksumSize == 16 || checksumSize == 32) {
            while (message.length() % (checksumSize / 8) != 0) {
                message += "X";
            }
        }

        // split message
        for (int i = 0; i < message.length(); i += 80) {
            System.out.println(message.substring(i, i + 80 > message.length() ? message.length() : i + 80));
        }

        // compute checksum
        switch (checksumSize) {
            case 8:
                System.out.println(" 8 bit checksum is " + computeChecksum8(message) + " for all " + message.length() + " chars");
                break;
            case 16:
                System.out.println("16 bit checksum is " + computeChecksum16(message) + " for all " + message.length() + " chars");
                break;
            case 32:
                System.out.println("32 bit checksum is " + computeChecksum32(message) + " for all " + message.length() + " chars");
                break;
            default:
                System.err.println("Valid checksum sizes are 8, 16, or 32");
                break;
        }

        messageScanner.close();
    }
}

/*=============================================================================
| I David Robinson (5514685) affirm that this program is
| entirely my own work and that I have neither developed my code together with
| any another person, nor copied any code from any other person, nor permitted
| my code to be copied or otherwise used by any other person, nor have I
| copied, modified, or otherwise used programs created by others. I acknowledge
| that any violation of the above terms will be treated as academic dishonesty.
+=============================================================================*/