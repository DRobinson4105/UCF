#include <stdint.h>

/*
Iterate through all 32 bits and count the number of ones

1. While n is greater than 0
    - Increment count if last bit is 1
    - Right shift to move to next bit in n
2. Return the count
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while (n) {
            count += n % 2;
            n >>= 1;
        }

        return count;
    }
};