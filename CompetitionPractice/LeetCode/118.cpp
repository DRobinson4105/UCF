#include <vector>

using namespace std;

/*
Build a pascal's triangle with a given number of rows where the first and last number
in each row is 1 and every other number is the sum of the two numbers above it

1. Loop through each row in the triangle
    - Loop through each index in that row
        - If the index is the first or last in that
          row, set that value in the current row to 1
        - Otherwise, set the value to the sum of the elements
          at the indexes [i-1] and [i] in the previous row
*/

class Solution {
public:
    vector<int> addRow(vector<vector<int>> triangle, int row) {
        vector<int> rowVec;

        for (int i = 0; i < row; i++) {
            // If index is first or last in row
            if (i == 0 || i == row - 1)
                rowVec.push_back(1);
            else
                rowVec.push_back(triangle[row - 2][i - 1] + triangle[row - 2][i]);
        }

        return rowVec;
    }

    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> triangle(numRows);
        
        for (int i = 0; i < numRows; i++) {
            // Add each row to triangle
            triangle[i] = addRow(triangle, i + 1);
        }
            

        return triangle;
    }
};