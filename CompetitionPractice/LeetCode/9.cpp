#define ONESPLACE(num) ((int)(num - ((int)num/10) * 10))

using namespace std;

/*
Compare the number to the same number with all digits moved to the 
right side of decimal point except for ones place to compare each digit

1. Save another integer, x but all digits except for
last are shifted to right of decimal point (123 -> 1.23)
2. Loop through half of the digits
    - If the ones digits of the two numbers do not match, return false
    - Shift the two numbers to the next digit
3. Once loop completes, return true
*/
class Solution {
public:
    bool isPalindrome(int x) {
        // If number is negative
        if (x < 0) return false;

        // Create the another number to compare x to
        double opposite = x;
        int numDigits = 0;
        while ((int) opposite > 0) {
            opposite /= 10;
            numDigits++;
        }

        opposite *= 10;

        // Compare each digit of the two numbers
        for (int i = 0; i < numDigits / 2; i++) {
            // If one of the digits fails the palindrome
            if (ONESPLACE(opposite) != ONESPLACE(x))
                return false;

            // Shift to next digits
            opposite *= 10;
            x /= 10;
        }

        // If x is a palindrome
        return true;
    }
};