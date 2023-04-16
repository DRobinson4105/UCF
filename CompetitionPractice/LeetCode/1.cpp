#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
Use hashmap to keep track of used values until the compliment of a used value is found

1. Create an empty unordered map to store the elements of the array
2. Loop through the array and for each element, calculate
the complement of the current element (target - element)
	- If the complement exists in the unordered map, return the indices of the two elements
	- Otherwise, add the current element to the unordered map
3. If no such pair is found, return an empty vector
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> usedValues;

		// Check if each number is part of the two sum
		for (int i = 0; i < nums.size(); i++) {
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