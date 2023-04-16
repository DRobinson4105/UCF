#include <vector>

using namespace std;

/*
Keep counter of unique numbers and loop through nums checking if a unique value
is found, adding them to end of unique values in vector and returning counter

1. Keep counter of unique numbers, starting at 1
2. Iterate through nums
    - If number is not equal to the next number, add to next 
      index tracked by counter and increment counter
3. Return counter
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] != nums[i+1])
                nums[j++] = nums[i+1];

        return j;
    }
};