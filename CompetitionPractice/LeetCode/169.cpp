#include <vector>

using namespace std;

/*
Keep a counter and a tracked number repeatedly comparing each set of two numbers,
incremementing it if they are equal or decrementing it if they are not and
replacing the tracked number with the current number if the counter reaches 0
Since there is a majority element that appears more than n/2 times, that
number will always be the one being tracked by the counter by the end

1. Start counter at 1 and tracked number at the first number
2. For each number in vector starting at second
    - If the current number is equal to the tracked number, increment counter
    - Otherwise, decrement counter
    - If counter is 0, set tracked number to current number and increment counter
3. Return the tracked number
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Track the first number initially
        int counter = 1;
        int num = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != num)
                counter--;
            else
                counter++;

            // New number needs to be tracked
            if (counter == 0) {
                counter = 1;
                num = nums[i];
            }
        }

        return num;
    }
};