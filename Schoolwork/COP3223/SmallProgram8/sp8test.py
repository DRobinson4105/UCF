#Dr. Andrew Steinberg
#COP3223C Student Python Script v1.1
#This script will automatically compile, run, and compare your results to a provided txt file that contains sample output.
#DO NOT MODIFY THE CONTENTS OF THIS FILE!
#You do not need understand this code as this is out of the scope of this course. However, if you are interested you can discuss with Dr. Steinberg
#New to v1.1 update, leading and trailing whitespace is automatically eliminated.

import os
import sys
import subprocess
import functools

#this is where we will put the input... yes they are global variables but this is ok to do for this scenario since this is a script
#it is list and each item will be string representing input for each question
#example  ['1 2 3', '2' , '4.2 41.4']
#qinputs = ['4 1 Kasey\n Moss\n The Lucy Show\n 1 Estrella\n Holder\n Loki\n 1 Zara\n Forbes\n Modern Family\n 2 1 Adam\n Goldberg\n The Goldbergs\n 1 Terrence\n Shaffer\n The Good Place\n 2 3 3 2 1 Harry\n Potter\n Stranger Things\n 2 1 Gary\n Foley\n The Flight Attendant\n 2 3 5 2 1 Tiffany\n Rivera\n Full House\n 2 4'] 

qinputs = ['4\n 1\n Kasey\n Moss\n The Lucy Show\n 1\n Estrella\n Holder\n Loki\n 1\n Zara\n Forbes\n Modern Family\n 2\n 1\n Adam\n Goldberg\n The Goldbergs\n 1\n Terrence\n Shaffer\n The Good Place\n 2\n 3\n 3\n 2\n 1\n Harry\n Potter\n Stranger Things\n 2\n 1\n Gary\n Foley\n The Flight Attendant\n 2\n 3\n 5\n 2\n 1\n Tiffany\n Rivera\n Full House\n 2\n 4\n']

smallprogramo = 'smallprogram8'
solutiontxt = 'samplesolutionsp8.txt'
studentsoltxt = 'smallprogram8solution_student_output.txt'

def result():
    cwd = os.getcwd()
    
    f1 = open(cwd + '/' + solutiontxt, "r")
    f2 = open(cwd + '/' + studentsoltxt, "r")
    
    #read output from each text file
    l1prestrip = f1.readlines()
    l2prestrip = f2.readlines()
    
    #remove leading and trailing whitespace
    l1 = [s.strip() for s in l1prestrip]
    l2 = [s.strip() for s in l2prestrip]
    
    
    #compare the content read
    if len(l1) == len(l2) and functools.reduce(lambda x, y : x and y, map(lambda p, q: p == q, l1, l2), True): 
        print("  ------  ")
        print(" / o  o \ ")
        print("|        |")
        print("| \____/ |")
        print(" \      / ")
        print("  ------  ")
        print("YES!!!! My file output matched Dr. Steinberg's sample output!")
    else: 
        os.system('cowsay -f turkey Gobble! Gobble! You have some errors with your output. Keep moving forward, your willingness and dedication to finishing this assignment is key to success')

    
    f1.close()
    f2.close()
    
    

def compilerunfile():
    cwd = os.getcwd()
    
    #gcc compile command the executable will be smallprogram 0 instead of a.out

    for subdir, dirs, files in os.walk(cwd):
        for myfile in files:
            if myfile[:13] == smallprogramo and myfile[-2:] == '.c':
                gcccmd = "gcc -o " + smallprogramo + " " + myfile + " -lm" #compile solution file command and generate executable called smallprogram1

                proc = subprocess.run([gcccmd], capture_output=True, text = True, shell = True)
                
                if(len(str(proc.stderr)) > 0):
                    print("Ugh oh... Your program had warning/error messages! Try to fix them or else points are deducted.")
                    print("------------------------------------------------------------------------")
                    print(str(proc.stderr))
                    print("------------------------------------------------------------------------")
        break
    
    crun = "valgrind --leak-check=yes ./" + smallprogramo
    
    f = open(studentsoltxt, "w")
    
    #list comprehension
    inputs = ' '.join([str(item) for item in qinputs])
    
    proc2 = subprocess.run([crun], capture_output=True, input = inputs, text = True, shell = True, timeout= 3) 
    
    if(proc2.stderr.find('All heap blocks were freed -- no leaks are possible') == -1):
        print("Ugh oh... You have memory leaks! Make sure to fix those!")
        print("------------------------------------------------------------------------")
        print(str(proc2.stderr))
        print("------------------------------------------------------------------------")
    
    f.write(str(proc2.stdout))

    print("Done running the student's solution.")
    f.close()


def setupchecker():
    print("We are now checking to make sure you have all necessary files in the same directory.")
    cwd = os.getcwd() #this grabs the current directory as it varies for each student based on NID
    
    #first check to see if solution txt file exists in the same directory as this script
    
    if not os.path.exists(cwd + "/" + solutiontxt):
        raise FileNotFoundError("The provided sample solution text file is not in the currect directory as this script." + 
        " Please place the text file in this directory and try again. Script Exiting!")
        
    
    
    #check to see if c file is placed properly. Only checks parts of it. Student is responsible for naming it properly with respective name as stated in the directions.
    flag = 0
    for subdir, dirs, files in os.walk(cwd):
        for myfile in files:
            if myfile[:13] == smallprogramo and myfile[-2:] == '.c':
                flag = 1
        break
    
    if flag == 0:
        raise FileNotFoundError("You are missing your C source!! Please put in your smallprogram8_lastname_firstname.c file. Script Exiting!")
        
    print("We are done with checking to make sure necessary files were provided.")
    

def main():
    print("Beginning the test of my program compared with a provided txt file from Dr. Steinberg.")
    print("Before this script tests the program, we need to make sure you have everything in order.")
    setupchecker()
    print("Setup is now complete. Begin testing.")
    print("Now it is time to compile the file.")
    compilerunfile()
    print("Now it is time for the moment of truth. Comparing my file output with Dr. Steinberg's sample solution file.")
    result()
    
    
    

if __name__ == "__main__":
    main()