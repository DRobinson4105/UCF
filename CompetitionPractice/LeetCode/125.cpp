#include <string>

using namespace std;

/*
Start with tracking the first and last index in the string and compare
each set of alphanumeric characters until the two indexes reach the middle

1. Start i at first index and j at last index
2. Loop until indexes cross
    - Move i to next alphanumeric character
    - Move j to next alphanumeric character
    - If characters at i and j are not equal (ignoring case), return false
3. Return true when loop completes
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int sLen = s.length();

        for (int i = 0, j = sLen - 1; i < j; i++, j--) {
            // Move i to next alphanumeric character
            while (!isalnum(s[i]) && i < j)
                i++;

            // Move j to next alphanumeric character
            while (!isalnum(s[j]) && i < j)
                j--;

            // Compare characters ignoring case
            if (tolower(s[i]) != tolower(s[j]))
                return false;
        }

        return true;
    }
};