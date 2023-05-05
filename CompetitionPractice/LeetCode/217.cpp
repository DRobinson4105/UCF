#include <vector>
#include <unordered_set>

using namespace std;

/*
Use a set to record used nums and loop through vector, checking if a number is already used

1. For each number in nums
    - If number is already in set, return true
    - Otherwise, insert number into set
2. Return false when loop completes
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> containedNums;
        for (int i = 0; i < nums.size(); i++) {
            // If number is already in set
            if (containedNums.count(nums[i]) > 0)
                return true;

            containedNums.insert(nums[i]);
        }

        return false;
    }
};