#include <string>

using namespace std;

/*
Convert the string reversed into base 26

1. Keep a multiplier to track the current unit in the base 26 (26^0, 26^1, 26^2)
2. Loop for every character in string starting at the end
    - Add the current character as a number (where A is 1) times the multiplier to a sum
    - Multiply the multiplier by 26
3. Return the sum
    
*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long int sum = 0;
        long long int mult = 1;

        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            sum += (columnTitle[i] - 'A' + 1) * mult;
            mult *= 26;
        }

        return sum;
    }
};