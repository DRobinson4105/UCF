#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleLength = needle.length();
        int stringLength = haystack.length();
        int iterations = stringLength - needleLength;
        for (int i = 0; i <= iterations; i++)
        {
            if (needle.compare(haystack.substr(i, needleLength)) == 0)
                return i;
        }

        return -1;
    }
};