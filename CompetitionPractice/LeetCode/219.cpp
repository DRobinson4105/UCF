#include <unordered_map>
#include <vector>

using namespace std;

/*
Use a map to contain used values and the index that they
are at and return true if a number is used within k indexes

1. Use map to map used values to the index that they are at
2. For each number in vector
    - If a number is already used and is within k elements, return true
    - Otherwise, map current value to current index
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> containedNums;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            // If a number is already used and is within k elements
            if (containedNums.find(nums[i]) != containedNums.end() && i - containedNums[nums[i]] <= k)
                return true;
            else
                containedNums[nums[i]] = i;
        }

        return false;
    }
};