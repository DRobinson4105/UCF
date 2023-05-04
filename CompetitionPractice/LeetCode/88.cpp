#include <vector>

using namespace std;

/*
Merge sort two arrays into nums1 starting from end to beginning

1. Starting at the last numbers in nums1 and nums2 repeatedly add the
   higher of the two numbers to the end of the nums1 vector and move to next number
2. Add any remaining numbers from nums2 to nums1
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // Merge lists into nums1 in a sorted order
        while (i >= 0 && j >= 0)
            nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        
        // Merge any remaining elements from nums2 into sorted list
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};