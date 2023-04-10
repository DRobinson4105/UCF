#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> usedValues;
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++)
		{
			if (usedValues.count(target - nums[i]) > 0)
			{
				ans.push_back(usedValues.find(target - nums[i])->second);
				ans.push_back(i);
				break;
			}
			else
				usedValues.insert({nums[i], i});
		}
        return ans;
    }
};

int main() {
	Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
	nums = s.twoSum(nums, 9);
	cout << nums[0] << " " << nums[1] << endl;
    return 0;
}