#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strSize = strs.size();
        int prefixLength = 0;
        int firstLength = strs[0].length();
        for (int i = 0; i < firstLength; i++)
        {
            for (int j = 1; j < strSize; j++)
            {
                if (strs[0][i] != strs[j][i])
                    return strs[0].substr(0, prefixLength);
            }

            prefixLength++;
        }

        return strs[0];
    }
};