#include <string>

using namespace std;

/*
Find start and end index of last word and return difference of them

1. Start lastI at last index in string
2. Decrement lastI until s[lastI] is not a space
3. Start firstI at lastI
4. Decrement firstI until s[firstI] is a space so that s[firstI+1...lastI] is the word
5. Return the difference of lastI and firstI
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int lastI = s.length() - 1;
        int firstI;
        
        // Move lastI to last index of last word
        while (s[lastI] == ' ')
            lastI--;

        firstI = lastI;
        
        // Move firstI to space right before last word
        while (firstI >= 0 && s[firstI] != ' ')
            firstI--;
        
        return lastI - firstI;
    }
};