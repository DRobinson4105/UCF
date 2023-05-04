#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        for (int i = 0; i < nums.size() - i; i++)
            nums.push_back(nums[i]);

        return nums;
    }
};