#include <string>
#include <algorithm>

using namespace std;

/*
Convert the number into base 26 using letters instead of numbers for the answer

1. While the number is greater than 0
    - Subtract one from number since A is 1
    - Convert the mod26 of the number to a letter and add to end of result
    - Divide number by 26
2. Reverse answer since the lower unit needs to be at the front
3. Return result
*/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";

        while (columnNumber > 0) {
            columnNumber--;
            res += (columnNumber % 26 + 'A');
            columnNumber /= 26;
        }

        // Reverse string since lower units need to be at the front
        reverse(res.begin(), res.end());
        return res;
    }
};