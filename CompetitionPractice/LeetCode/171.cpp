#include <string>

using namespace std;

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