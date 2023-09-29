#include <iostream>
#include <vector>

using namespace std;

void calcPermutations(vector<bool> used, vector<int> array, vector<vector<int> >& result, vector<int> perm, int curr, int size) {
    if (curr == size) {
        result.push_back(perm);
    }

    for (int i = 0; i < size; i++) {
        if (used[i]) continue;

        used[i] = true;
        perm[curr] = array[i];
        calcPermutations(used, array, result, perm, curr + 1, size);
        used[i] = false;
    }
}

vector<vector<int> > permutations(vector<int> array) {
    int size = array.size();
    vector<bool> used(size);
    vector<int> perm(size);
    vector<vector<int> > result;
    calcPermutations(used, array, result, perm, 0, size);
    return result;
}

int main() {
    vector<int> array(4);

    for (int i = 0; i < 4; i++) {
        array[i] = i + 1;
    }

    vector<vector<int> > result = permutations(array);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }
}