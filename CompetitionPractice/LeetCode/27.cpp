#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        int numSize = nums.size();

        for (int i = 0; i < numSize; i++)
        {
            if (nums[i] == val) continue;

            nums[cur] = nums[i];
            cur++;
        }

        return cur;
    }
};