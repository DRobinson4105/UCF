// David Robinson
// COP 3330, Spring 2023
// da034737

import java.util.Scanner;

public class Strands
{
    // Prints the character array removing any spaces at the end of the array
    public static void printCharArray(char[] arr, int length)
    {
        // Starting with last index, decrement lastI until it is the last non-space character
        int lastI = length - 1;

        while (lastI >= 0 && arr[lastI] == ' ')
            lastI--;

        // Print array followed by a new line
        for (int i = 0; i <= lastI; i++)
            System.out.print(arr[i]);
        
        System.out.println();
    }

    // Prints n spaces followed by the character c
    public static void printCharAfterSpaces(char c, int n)
    {
        char[] curr = new char[n + 1];
        
        // Add n spaces to curr
        for (int i = 0; i < n; i++)
            curr[i] = ' ';
        
        // Add c to curr
        curr[n] = c;

        // Print curr
        printCharArray(curr, curr.length);
    }

    // Prints the string vertically with each character preceded by 2 spaces
    public static void straightAndNarrow(String str)
    {
        straightAndNarrow(str, 2);
    }

    // Prints the string vertically with each character preceded by n spaces
    public static void straightAndNarrow(String str, int n)
    {
        // If the string is null or empty
        if (str == null || str.length() == 0)
        {
            System.out.println("Pshh!");
            return;
        }

        // Holds all of the characters in the string
        char[] arr = str.toCharArray();

        // Prints each character after n spaces on a new line unless the character is a space
        for (int i = 0; i < arr.length; i++)
            printCharAfterSpaces(arr[i], n);
    }

    // Prints the string vertically with each character preceded by a certain number of spaces that follow a pattern:
    // 2, 2, 2, 3, 4, 5, 5, 5, 4, 3 (repeating) but the first element in the string has 3 spaces
    public static void meanderingPath(String str)
    {
        // The pattern for the indentation of each character
        int[] indents = {2, 2, 2, 3, 4, 5, 5, 5, 4, 3};

        // Holds all of the characters in the string
        char[] arr = str.toCharArray();
        
        for (int i = 0; i < arr.length; i++)
        {   
            // Print character after three spaces if first element or use indentation pattern for other elements
            printCharAfterSpaces(arr[i], (i == 0) ? 3 : indents[i % 10]);
        }
    }

    // Prints the strings vertically with each character in the first string following the meanderingPath()
    // and then every string after is preceded by two spaces where nth index of each array is printed on the nth line
    public static void classicRapunzel(String [] strings)
    {
        // The pattern for the indentation of first character on each line
        int[] indents = {2, 2, 2, 3, 4, 5, 5, 5, 4, 3};

        // Holds all strings as char arrays
        char[][] charArrays = new char[strings.length][];

        // Get highest string length in strings array and copy strings as char arrays
        int highest = 0;
        for (int i = 0; i < strings.length; i++)
        {
            charArrays[i] = strings[i].toCharArray();

            if (strings[i].length() > highest)
                highest = strings[i].length();
        }
        
        // Create char array to build the parts of each line on and then print it
        char[] curr = new char[strings.length * 3 + 3];
        int size;

        for (int i = 0; i < highest; i++)
        {
            // Adds initial amount of spaces
            int spaces = (i == 0) ? 3 : indents[i % 10];
            for(int j = 0; j < spaces; j++)
                curr[j] = ' ';
            
            // Adds the ith index of the first array to curr
            curr[spaces] = (charArrays[0].length > i) ? charArrays[0][i] : ' ';
            size = spaces + 1;
            
            // Adds two spaces and then the Ith element of the Jth array for each array after the first
            for (int j = 1; j < strings.length; j++)
            {
                curr[size] = ' ';
                curr[size + 1] = ' ';
                curr[size + 2] = (charArrays[j].length > i) ? charArrays[j][i] : ' ';
                size += 3;
            }

            // Print the current line
            printCharArray(curr, size);
        }   
    }

    // Same as classicRepunzel() but each odd indexed string is moved down one line
    public static void steamyMocha(String[] strings)
    {
        char[] str;
        char[] temp;

        // Add one space at the beginning of every odd indexed string in the array
        for(int i = 1; i < strings.length; i += 2)
        {
            temp = strings[i].toCharArray();
            str = new char[strings[i].length() + 1];

            str[0] = ' ';
            for(int j = 1; j < str.length; j++)
                str[j] = temp[j - 1];

            strings[i] = String.valueOf(str);
        }

        // Run the classicRepunzel code with the shifted strings
        classicRapunzel(strings);
    }

    // Same as classicRepunzel() but the Ith index string is shifted down I times
    public static void cascadingWaterfall(String[] strings)
    {
        char[] str;
        char[] temp;

        // Add i number of spaces at the beginning of every string in the array
        for(int i = 0; i < strings.length; i++)
        {
            temp = strings[i].toCharArray();
            str = new char[strings[i].length() + i];
            
            for(int j = 0; j < i; j++)
                str[j] = ' ';

            for(int j = 0; j < temp.length; j++)
                str[j + i] = temp[j];
            
            strings[i] = String.valueOf(str);
        }

        // Run the classicRepunzel code with the shifted strings
        classicRapunzel(strings);
    }

    public static double difficultyRating()
    {
        return 3;
    }

    public static double hoursSpent()
    {
        return 2;
    }
}