#include <vector>
#include <cmath>

using namespace std;

/*
Build the nth row of the pascal's triangle using binomial coefficients

1. Loop through each index in that row
    - If the index is the first or last in that
      row, set that value in the current row to 1
    - Otherwise, set the value to the binomial coefficient (size of row, index in row)
*/

class Solution {
public:
    int binomialCoefficient(int k, int n) {
        long double res = 1;
        int num = n - k;

        // Divide answer by (n-k)!
        for (int i = 2; i <= num; i++)
            res /= i;

        // Multiply answer by n!/k!
        for (int i = k + 1; i <= n; i++)
            res *= i;

        return round(res);
    }

    vector<int> getRow(int rowIndex) {
        vector<int> row;

        for (int k = 0; k <= rowIndex; k++) {
            // If index is first or last in row
            if (k == 0 || k == rowIndex)
                row.push_back(1);
            else
                row.push_back(binomialCoefficient(k, rowIndex));
        }

        return row;
    }
};