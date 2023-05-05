#include <vector>

using namespace std;

/*
Add all of the numbers in the vector and use the bitwise operator XOR to remove duplicates

1. Start the result at 0
2. For every number in the vector, set the result to (result XOR num)
3. Result will be the single number
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        
        // Set the res to res XOR x for every num in vector
        for (int x : nums)
            res^=x;
        
        return res;
    }
};