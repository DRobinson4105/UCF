#include <vector>

using namespace std;

/*
Keep counter of numbers not equal to val and loop through nums checking if a new
value is found, adding them to end of non-val numbers in vector and returning counter

1. Keep counter of non-val numbers, starting at 0
2. Iterate through nums
    - If number is not equal to val, add to next index tracked by counter and increment counter
3. Return counter
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[j++] = nums[i];

        return j;        
    }
};