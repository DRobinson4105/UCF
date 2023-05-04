#include <string>
#include <algorithm>

using namespace std;

/*
Starting at last numbers in a and b, add numbers and add 
result to answer, carrying 1 to the next number if needed

1. Loop until both strings have been completed and there is nothing left to carry over
    - Take the carry from last loop and add last digit in both strings to it
    - Add the sum to answer
    - If the sum is greater than 1, subtract 2 from itand carry over 1 to next number
*/

class Solution {
    public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;

        // Initialize i and j to be the last indexes of the strings
        int i = a.length() - 1;
        int j = b.length() - 1;

        // Add each value to the answer
        while (i >= 0 || j >= 0 || carry) {
            // Add value of a[i] to carry and decrement i
            if (i >= 0)
                carry += a[i--] - '0';
            
            // Add value of b[j] to carry and decrement j
            if (j >= 0)
                carry += b[j--] - '0';

            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};