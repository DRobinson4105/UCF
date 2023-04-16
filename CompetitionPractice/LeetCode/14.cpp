#include <vector>
#include <string>

using namespace std;

/*
Start prefix length at first string length and iterate through rest of strings, 
lowering prefix length if needed each time until all strings have been checked

1. Set the prefix to the first string
2. Compare each string to the first string until looped 
   through all strings or there is no common prefix
    - If the two strings have a smaller prefix than the current common prefix,
      Set the common prefix to the smaller prefix
3. Return the substring of the first string[0, commonPrefix-1]
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strSize = strs.size();
        int commonPrefix = strs[0].length();
        int firstLength = strs[0].length();

        for (int i = 1; i < strSize && commonPrefix > 0; i++) {
            int strLength = strs[i].length();
            int currPrefix = 0;

            // Shift common prefix to first character that is not equal in the two strings
            while (currPrefix < firstLength && currPrefix < strLength && 
                    strs[0][currPrefix] == strs[i][currPrefix])
                currPrefix++;

            // If the common prefix is more than the current common prefix,
            // set it to the current prefix
            if (currPrefix < commonPrefix)
                commonPrefix = currPrefix;
        }

        // Return substring of first string[0, commonPrefix - 1]
        return strs[0].substr(0, commonPrefix);
    }
};