#include <string>

using namespace std;

/*
Iterate through string and add the current roman numeral to a sum

1. Loop through each character of the string
    - Check which roman numeral the character is
    - Use the next roman numeral to see if subtraction is used
    - Add to sum
2. Return sum
*/
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int stringlen = s.length();
        
        // Check each character in the string
        for (int i = 0; i < stringlen; i++) {
            switch(s[i]) {
                case 'M':
                    sum += 1000;
                    break;

                case 'D':
                    sum += 500;
                    break;

                case 'C':
                    // If string includes 'CM'
                    if (i < stringlen - 1 && s[i + 1] == 'M') {
                        sum += 900;
                        i++;
                        break;
                    }
                    
                    // If string includes 'CD'
                    if (i < stringlen - 1 && s[i + 1] == 'D') {
                        sum += 400;
                        i++;
                        break;
                    }
                    sum += 100;
                    break;

                case 'L':
                    sum += 50;
                    break;

                case 'X':
                    // If string includes 'XC'
                    if (i < stringlen - 1 && s[i + 1] == 'C') {
                        sum += 90;
                        i++;
                        break;
                    }

                    // If string includes 'XL'
                    if (i < stringlen - 1 && s[i + 1] == 'L') {
                        sum += 40;
                        i++;
                        break;
                    }
                    sum += 10;
                    break;

                case 'V':
                    sum += 5;
                    break;

                case 'I':
                    // If string includes 'IX'
                    if (i < stringlen - 1 && s[i + 1] == 'X') {
                        sum += 9;
                        i++;
                        break;
                    }

                    // If string includes 'IV'
                    if (i < stringlen - 1 && s[i + 1] == 'V') {
                        sum += 4;
                        i++;
                        break;
                    }
                    sum += 1;
                    break;
            }
        }

        return sum;
    }
};