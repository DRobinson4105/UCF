#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int sLen = s.length();
        int j = sLen - 1;

        for (int i = 0; i < sLen && i < j; i++, j--) {
            while (!isalnum(s[i]) && i < j)
                i++;
            while (!isalnum(s[j]) && i < j)
                j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;
        }

        return true;
    }
};