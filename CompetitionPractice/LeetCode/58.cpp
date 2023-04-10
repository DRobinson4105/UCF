#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int lastI = s.length() - 1;
        int firstI;
        
        while (s[lastI] == ' ')
            lastI--;

        firstI = lastI;
        
        while (firstI >= 0 && s[firstI] != ' ')
            firstI--;
        
        return lastI - firstI;
    }
};