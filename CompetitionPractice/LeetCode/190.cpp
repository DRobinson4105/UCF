#include <stdint.h>

/*
Add all of the digits in reverse order to a number

1. Start at the end of the answer and beginning of given number
2. For every bit in a 32-bit number
    - Add bit from given number to answer
    - Move current bit in given number to left bit
    - Move current bit in answer to right bit
3. Return answer
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int curr = 31;
        
        while (curr >= 0) {
            res += ((n % 2) << curr);
            curr--;
            n >>= 1;
        }

        return res;
    }
};