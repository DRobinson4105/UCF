#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique = 0;
        int numSize = nums.size();
        for (int i = 0; i < numSize; i++)
        {
            if (nums[i] == nums[unique]) continue;

            nums[unique + 1] = nums[i];
            unique++;
        }

        return unique + 1;
    }
};