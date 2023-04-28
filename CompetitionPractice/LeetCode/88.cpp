#include <vector>

using namespace std;

/*
Merge sort two arrays into nums1 starting from end to beginning
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // Merge lists into nums1
        while (i >= 0 && j >= 0)
            nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];

        // Merge any remaining elements from nums1 into sorted list
        while (i >= 0)
            nums1[k--] = nums1[i--];
        
        // Merge any remaining elements from nums2 into sorted list
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};