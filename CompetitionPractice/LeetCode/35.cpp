#include <vector>

using namespace std;

/*
Use a binary search to find where target should be in the vector

1. Repeat process until target is found or [low, high] has no range
    - If [low, high] has no range, insert target at the correct spot near nums[low]
    - If middle value is equal to target, return middle index
    - If middle value is greater than target, set upper bound to middle index
    - If middle value is less than target, set lower bound to middle index
*/

class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        // If target was not found and needs to be added
        if (low >= high) {
            // If target should be added after nums[low]
            if (nums[low] < target) {
                nums.insert(nums.begin() + low + 1, target);
                return low + 1;
            }

            // If target should be added before nums[low]
            nums.insert(nums.begin() + low, target);
            return low;
        }

        int mid = (low + high) / 2;

        // If target was found
        if (target == nums[mid])
            return mid;

        // If target is in left side of current range
        if (target < nums[mid])
            return binarySearch(nums, low, mid - 1, target);

        // If target is in right side of current range
        return binarySearch(nums, mid + 1, high, target);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};