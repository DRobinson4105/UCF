#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> containedNums;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (containedNums.find(nums[i]) == containedNums.end() || i - containedNums[nums[i]] > k)
                containedNums[nums[i]] = i;
            else
                return true;
        }

        return false;
    }
};