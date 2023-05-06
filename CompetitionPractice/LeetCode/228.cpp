#include <vector>
#include <string>

using namespace std;

/*
Iterate through nums, adding an interval for every group of
consecutive integers and just the number for standalone numbers

1. Use a vector to track intervals
2. If nums is empty, return the empty vector
3. Keep track of the start of the current interval, starting at the first number
4. For every num except for last, if the next number
   is at least two more than the current number
   - If the current number is the only number in its interval, add that number by itself
   - Otherwise, add the interval in the format (start->end)
5. Return vector of intervals
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;

        int size = nums.size();
        if (!size) return ranges;
        
        int start = nums[0];
        for (int i = 0; i < size - 1; i++) {
            if (nums[i + 1] > nums[i] + 1) {
                if (nums[i] == start)
                    ranges.push_back(to_string(start));
                else
                    ranges.push_back(to_string(start) + "->" + to_string(nums[i]));
                start = nums[i + 1];
            }
        }

        if (nums[size - 1] == start)
            ranges.push_back(to_string(start));
        else
            ranges.push_back(to_string(start) + "->" + to_string(nums[size - 1]));

        return ranges;
    }
};