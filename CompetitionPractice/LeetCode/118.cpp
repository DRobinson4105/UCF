#include <vector>

using namespace std;

class Solution {
public:
    vector<int> addRow(vector<vector<int>> triangle, int row) {
        vector<int> rowVec;

        for (int i = 0; i < row; i++) {
            if (i == 0 || i == row - 1)
                rowVec.push_back(1);
            else
                rowVec.push_back(triangle[row - 2][i - 1] + triangle[row - 2][i]);
        }

        return rowVec;
    }
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> triangle(numRows);

        for (int i = 0; i < numRows; i++)
            triangle[i] = addRow(triangle, i + 1);

        return triangle;
    }
};