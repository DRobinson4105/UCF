/*============================================================================
| Assignment: pa01 - Encrypting a plaintext file using the Hill cipher
|
| Author: David Robinson
| Language: Java
|
| To Compile: javac pa01.java
|
| To Execute: java -> java pa01 kX.txt pX.txt
|
| Note:
| All input files are simple 8 bit ASCII input
| All execute commands above have been tested on Eustis
|
| Class: CIS3360 - Security in Computing - Fall 2023
| Instructor: McAlpin
| Due Date: 10/08/2023
+===========================================================================*/

import java.util.Scanner;
import java.util.NoSuchElementException;
import java.io.File;
import java.io.FileNotFoundException;

public class pa01 {
    public static String simplifedString(String s) {
        String result = "";
        for (int i = 0; i < s.length(); i++) {
            char curr = Character.toLowerCase(s.charAt(i));
            if (isAlpha(curr))
                result += curr;
        }

        return result;
    }

    public static boolean isAlpha(char c) {
        return c >= 'a' && c <= 'z';
    }

    public static void main(String[] args) {
        try {
            File keyFile = new File(args[0]);
            File plaintextFile = new File(args[1]);
            Scanner keyScanner = new Scanner(keyFile);
            Scanner plaintextScanner = new Scanner(plaintextFile);

            int n = keyScanner.nextInt();
            int[][] key = new int[n][n];
            String plaintext = "";
            String curr = "";
            int[] startingLetters = new int[n];
            String result = "";

            System.out.println();
            System.out.println("Key matrix:");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    key[i][j] = keyScanner.nextInt();

                    System.out.print(" ");
                    System.out.print(key[i][j]);
                }
                System.out.println();
            }
            
            while (true) {
                plaintext += curr;
                try {
                    curr = plaintextScanner.nextLine();
                } catch (NoSuchElementException e) {
                    break;
                }
            }

            plaintext = simplifedString(plaintext);

            for (int i = 0; i < plaintext.length(); i += n) {
                for (int j = i; j < i + n; j++) {
                    if (j == plaintext.length()) {
                        for (int k = j; k < i + n; k++) {
                            startingLetters[k - i] = 23;
                            plaintext += "x";
                        }
                        break;
                    }
                    startingLetters[j - i] = plaintext.charAt(j) - 'a';
                }

                for (int j = 0; j < n; j++) {
                    int sum = 0;
                    for (int k = 0; k < n; k++) {
                        sum += startingLetters[k] * key[j][k];
                    }
                    result += (char)((sum % 26) + 'a');
                }
            }
            
            System.out.println();
            System.out.println("Plaintext:");
            for (String part : plaintext.split("(?<=\\G.{80})"))
                System.out.println(part);

            System.out.println();
            System.out.println("Ciphertext:");
            for (String part : result.split("(?<=\\G.{80})"))
                System.out.println(part);

            keyScanner.close();
            plaintextScanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
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