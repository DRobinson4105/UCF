#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> containedNums;
        for (int i = 0; i < nums.size(); i++) {
            if (containedNums.count(nums[i]) > 0)
                return true;

            containedNums.insert(nums[i]);
        }

        return false;
    }
};