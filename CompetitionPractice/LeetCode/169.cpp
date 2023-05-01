#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 1;
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != num)
                counter--;
            else
                counter++;

            if (counter <= 0) {
                counter = 1;
                num = nums[i];
            }
        }

        return num;
    }
};