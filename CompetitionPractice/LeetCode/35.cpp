#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        if (low >= high) {
            if (nums[low] < target) {
                nums.insert(nums.begin() + low + 1, target);
                return low + 1;
            }
            nums.insert(nums.begin() + low, target);
            return low;
            
        }
        int mid = (low + high) / 2;

        if (target == nums[mid])
            return mid;

        if (target < nums[mid])
            return binarySearch(nums, low, mid - 1, target);

        return binarySearch(nums, mid + 1, high, target);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};