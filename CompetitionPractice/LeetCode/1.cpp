#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> usedValues;

		// Check if each number is part of the two sum
		for (int i = 0; i < nums.size(); i++)
		{
			// If the current number's compliment does not exist in the vector
			if (usedValues.count(target - nums[i]) == 0)
				usedValues.insert({nums[i], i});

			// Found the current number's compliment
			else
				return {usedValues.find(target - nums[i])->second, i};
		}

        return {};
    }
};