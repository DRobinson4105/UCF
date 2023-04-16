#include <string>

using namespace std;

/*
Check each possible location for needle

1. Loop through possible starting locations for needle
    - If found, return the starting index
2. Return -1 since it was not found
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleLength = needle.length();
        int stringLength = haystack.length();
        int iterations = stringLength - needleLength;

        for (int i = 0; i <= iterations; i++)
            if (needle.compare(haystack.substr(i, needleLength)) == 0)
                return i;

        return -1;
    }
};