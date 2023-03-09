#Dr. Andrew Steinberg
#COP3223C Student Python Script v2.0 for Small Program 5
#This script will automatically compile, run, and compare your results to a provided txt file that contains sample output.
#DO NOT MODIFY THE CONTENTS OF THIS FILE!
#You do not need understand this code as this is out of the scope of this course. However, if you are interested you can discuss with Dr. Steinberg
#New to v2.0 update, a diff function was created to help student see where there error lies in output and now students will have 5 test cases

import os
import sys
import subprocess
import functools

#this is where we will put the input... yes they are global variables but this is ok to do for this scenario since this is a script
#it is list and each item will be string representing input for each question
#example  ['1 2 3', '2' , '4.2 41.4']
qinputs1 = ['0.10\n0.21\n1\n2\n2\n4\n4\n4\n6\n6\n0\n0\n0\n0\n0\n1'] 
qinputs2 = ['0.15\n0.26\n1\n1\n1\n2\n2\n2\n3\n2\n3\n5\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n4'] 
qinputs3 = ['0.35\n0.61\n3\n4\n5\n6\n6\n6\n5\n4\n3\n4\n5\n4\n3\n2\n1\n1\n2\n2\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n6'] 
qinputs4 = ['0.70\n0.83\n1\n3\n4\n5\n6\n5\n4\n\n2\n1\n3\n4\n5\n4\n3\n2\n3\n2\n3\n2\n3\n4\n0\n0\n0\n0\n0\n3'] 
qinputs5 = ['0.45\n0.57\n1\n1\n1\n1\n1\n1\n1\n1\n2\n2\n2\n2\n2\n2\n2\n6\n6\n6\n6\n6\n6\n2\n3\n4\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n2'] 
testcases = [qinputs1, qinputs2, qinputs3, qinputs4, qinputs5]


def diff(l1, l2):
    for line in range(0, len(l1)):
        line1 = l1[line]
        
        line2 = ""
        if line < len(l2):
            line2 = l2[line]
            
        if line1 != line2:
            print("These two lines are different in output")
            print("Steinberg Output: " + line1)
            print("Student's Output: " + line2)
            
    if len(l1) != len(l2):
        print("------------------------------------------------")
        print("Your output is missing content on certain lines.")
        print("------------------------------------------------")
        
def diffFile(l1, l2):
    for line in range(0, len(l1)):
        line1 = l1[line]
        
        line2 = ""
        if line < len(l2):
            line2 = l2[line]
            
        if line1 != line2:
            print("These two lines are different in the text file")
            print("Steinberg Output: " + line1)
            print("Student's Output: " + line2)
            
    if len(l1) != len(l2):
        print("------------------------------------------------")
        print("Your text file is missing content on certain lines.")
        print("------------------------------------------------")
        


def result():
    cwd = os.getcwd()

    scenario = 1
    
    passes = 0
    
    for test in testcases:
        f1 = open(cwd + '/samplesolutionsp5testcase' + str(scenario) + '.txt', "r")
        f2 = open('sp5student_output_test_case_' + str(scenario) + '.txt', "r")
        f3 = open('myreceipt_testcase_' + str(scenario)+ '.txt', "r")
        f4 = open('steinbergreceipt_testcase_' + str(scenario)+ '.txt', "r")
        
        #remove leading and trailing whitespace
        l1prestrip = f1.readlines()
        l2prestrip = f2.readlines()
        l3prestrip = f3.readlines()
        l4prestrip = f4.readlines()
        
        #remove leading and trailing whitespace
        l1 = [s.strip() for s in l1prestrip]
        l2 = [s.strip() for s in l2prestrip]
        l3 = [s.strip() for s in l3prestrip]
        l4 = [s.strip() for s in l4prestrip]
        
        
        #compare the content read
        if (len(l1) == len(l2) and functools.reduce(lambda x, y : x and y, map(lambda p, q: p == q, l1, l2), True)) and (len(l3) == len(l4) and functools.reduce(lambda x, y : x and y, map(lambda p, q: p == q, l3, l4), True)):
            print("TEST CASE " + str(scenario) + " PASSED!")
            passes = passes + 1
        else: 
            print("TEST CASE " + str(scenario) + " FAILED!")
            inputs = ' '.join([str(item) for item in test])
            print("The inputs used for this test case were " + inputs.replace('\n', ' '))
            diff(l1, l2)
            diffFile(l3, l4)
        
        scenario = scenario + 1
    
    if passes == 5:
        print("  ------  ")
        print(" / o  o \ ")
        print("|        |")
        print("| \____/ |")
        print(" \      / ")
        print("  ------  ")
        print("YESSSSS!!! ALL TEST CASES PASSED!")
        print("DISCLAIMER! MAKE SURE TO CHECK YOUR CODE THAT YOU FOLLOWED ALL DIRECTIONS THE ASSIGNMENT ASKS FOR. REGARDLESS OF THE CORRECT OUTPUT, DR. STEINBERG AND HIS TAs WILL CHECK YOUR CODE TO ENSURE DIRECTIONS WERE FOLLOWED FOR EACH PROBLEM!")
    else:
        os.system("cowsay Hi there! I see you did not pass all the test cases. It is tough to get it 100% correct. You will get better and better as time progresses. Keep mooooooooooooooooooooving forward!")

    
    f1.close()
    f2.close()
    
    

def compilerunfile():
    cwd = os.getcwd()
    
    #gcc compile command the executable will be smallprogram 4 instead of a.out

    for subdir, dirs, files in os.walk(cwd):
        for myfile in files:
            if myfile[:13] == 'smallprogram5' and myfile[-2:] == '.c':
                gcccmd = "gcc -o " + "smallprogram5 " + myfile + " -lm" #compile solution file command and generate executable called smallprogram4

                proc = subprocess.run([gcccmd], capture_output=True, text = True, shell = True)
                
                if(len(str(proc.stderr)) > 0):
                    print("Ugh oh... Your program had warning/error messages! Try to fix them or else points are deducted.")
                    print("------------------------------------------------------------------------")
                    print(str(proc.stderr))
                    print("------------------------------------------------------------------------")
        break
    
    crun = "./" + "smallprogram5"
    
    
    
    
    scenario = 1
    for test in testcases:
    
        #list comprehension
        inputs = ' '.join([str(item) for item in test])
        f = open('sp5student_output_test_case_' + str(scenario) + '.txt', "w")
        f.write("----------------------------------------------------------------------\n")
        f.write("Testing Test Case " + str(scenario) + "\n")
        f.write("----------------------------------------------------------------------\n")
        
        
        try:
            os.rename("grades" + str(scenario) + ".txt", "grades.txt")
            proc2 = subprocess.run([crun], capture_output=True, input = inputs, text = True, shell = True, timeout= 2)
            os.rename("grades.txt", "grades" + str(scenario) + ".txt")
            f.write(str(proc2.stdout))
            f.close()
            
            if(len(str(proc2.stderr)) > 0):
                print("Ugh oh... Your program had error messages! Try to fix them or else points are deducted.")
                print("------------------------------------------------------------------------")
                print(str(proc2.stderr))
                print("------------------------------------------------------------------------")
            
        except subprocess.TimeoutExpired as e:
            
            if (e.stdout == None):
                print("Program Crashed for Test Case " + str(scenario) + ' with inputs ' + str(inputs))
                f.write("Program Crashed :( Please take a look at your logic in the code.")
            else:
                print("Your program is stuck in an infinite loop! Please make sure to fix that or else points are going to be deducted.")
            
            f.close()
        
        if(os.path.exists('myreceipt.txt')):
            os.rename("myreceipt.txt", "myreceipt_testcase_" + str(scenario) + ".txt")
        else:
            with open("myreceipt_testcase_" + str(scenario) + ".txt", 'w') as fp: #if does not exist to prevent FileNotFoundError
                pass
        
        
        scenario = scenario + 1
    

    print("Done running the student's solution.")
    


def setupchecker():
    print("We are now checking to make sure you have all necessary files in the same directory.")
    cwd = os.getcwd() #this grabs the current directory as it varies for each student based on NID
    
    #first check to see if solution txt file exists in the same directory as this script
    
    
    for x in range(1, 6):
        if not os.path.exists(cwd + "/samplesolutionsp5testcase" + str(x) + ".txt"):
            raise FileNotFoundError("The provided sample solution text file for test case " + str(x) + " is not in the currect directory as this script." + 
            " Please place the text file in this directory and try again. Script Exiting!")
       

    #check to see if c file is placed properly. Only checks parts of it. Student is responsible for naming it properly with respective name as stated in the directions.
    flag = 0
    for subdir, dirs, files in os.walk(cwd):
        for myfile in files:
            if myfile[:13] == 'smallprogram5' and myfile[-2:] == '.c':
                flag = 1
        break
    
    if flag == 0:
        raise FileNotFoundError("You are missing your C source!! Please put in your smallprogram4_lastname_firstname.c file. Script Exiting!")
        
    
    
    for x in range(1, 6):
        if not os.path.exists(cwd + "/grades" + str(x) +".txt"):
            raise FileNotFoundError("You are missing grades" + str(x) + ".txt! Please upload that file for testing!")
    
    for x in range(1, 6):
        if not os.path.exists(cwd + "/steinbergreceipt_testcase_" + str(x) + ".txt"):
            raise FileNotFoundError("You are steinbergreceipt_testcase_" + str(x) + ".txt! Please upload that file for testing!")
    
    
    if os.path.exists(cwd + "/grades.txt"):
        os.remove("grades.txt")
    

        
    
        
    
    
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