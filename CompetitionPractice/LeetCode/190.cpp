#include <stdint.h>

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