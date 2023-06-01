#include <bits/stdc++.h>

using namespace std;

int dirX[8] = {-1, -1, -1,  0,  1,  1,  1,  0};
int dirY[8] = {-1,  0,  1,  1,  1,  0, -1, -1};

int highest = 0;

int main() {
    int numRows, numCols, startRow, startCol, maxEnergy;
    queue<pair<int, int> > q;
    cin >> numRows >> numCols >> startRow >> startCol >> maxEnergy;

    startRow--;
    startCol--;

    // vector<vector<int> > maze(numRows);
    int** maze = new int*[numRows];
    bool** visited = new bool*[numRows];
    for (int i = 0; i < numRows; i++) {
        maze[i] = new int[numCols];
        visited[i] = new bool[numCols];

        for (int j = 0; j < numCols; j++) {
            cin >> maze[i][j];
            visited[i][j] = 0;
        }
    }

    q.push({startRow, startCol});
    

    return 0;
}