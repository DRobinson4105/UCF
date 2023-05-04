#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    long double fact(int num) {
        long double res = 1;

        for (int i = 2; i <= num; i++)
            res *= i;

        return res;
    }

    int doubleFact(long double startingVal, int num1, int num2) {
        long double res = 1 / startingVal;

        for (int i = num1 + 1; i <= num2; i++)
            res *= i;

        return (int)round(res);
    }

    vector<int> getRow(int rowIndex) {
        vector<int> row;

        for (int k = 0; k <= rowIndex; k++) {
            if (k == 0 || k == rowIndex)
                row.push_back(1);
            else
                row.push_back(doubleFact(fact(rowIndex - k), k, rowIndex));
        }

        return row;
    }
};