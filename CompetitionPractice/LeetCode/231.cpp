#include <cmath>

/*
The logarithm base 2 of a number will be an integer if it is a power of 2

1. If a number is 0 or negative, return false
2. If the logarithm base 2 of n is an integer, return true
3. Otherwise, return false
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n <= 0) ? false : (int)log2(n) == log2(n);
    }
};