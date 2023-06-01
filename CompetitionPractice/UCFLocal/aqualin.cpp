#include <iostream>
#include <vector>

using namespace std;

int dirX[4] = {1, -1, 0, 0};
int dirY[4] = {0, 0, 1, -1};

int main() {
    int n;
    cin >> n;
    vector<vector<char>> types(n);
    vector<vector<int>> colors(n);
    vector<int> typeTotal(26);
    vector<int> colorTotal(n);

    for (int i = 0; i < n; i++) {
        vector<char> typeRow;
        vector<int> colorRow;

        for (int j = 0; j < n; j++)
            cin >> typeRow[i] >> colorRow[i];

        types.push_back(typeRow);
        colors.push_back(colorRow);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (types[i][j] == 'a') continue;
            char curr = types[i][j];
            int total = 1;
            types[i][j] = 'a';
            
        }
    }

    return 0;
}