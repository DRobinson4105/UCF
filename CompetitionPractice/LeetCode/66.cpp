#include <vector>

using namespace std;

/*
Add one to the number and then carry any 1's over to earlier index

1. Increment last digit
2. If a one needs to be carried over, set it to 0 and add one to 
digits[i - 1], repeating process until all digits are less than 10
3. Return vector
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        // Add one to number represented by digits        
        digits[digits.size() - 1]++;

        // Carry any 1's over
        for (int i = digits.size() - 1; i > 0 && digits[i] == 10; i--) {
            digits[i] = 0;
            digits[i - 1]++;
        }

        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};