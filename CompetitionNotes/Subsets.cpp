#include <iostream>
#include <vector>

using namespace std;

bool on(int mask, int pos) {
    return (mask & (1 << pos)) > 0;
}

int set(int mask, int pos) {
    return mask | (1 << pos);
}

void calcSubsets(vector<int> array, vector<vector<int> >& result, int index, int size) {
    int total = 1 << size;
    for (int mask = 0; mask < total; mask++) {
        vector<int> subset;
        for (int k = 0; k < size; k++) {
            if (on(mask, k)) {
                subset.push_back(array[k]);
            }
        }
        result.push_back(subset);
    }
}

vector<vector<int> > subsets(vector<int>& array) {
    vector<vector<int> > result;
    calcSubsets(array, result, 0, array.size());
    return result;
}

int main() {
    vector<int> array(4);

    for (int i = 0; i < 4; i++) {
        array[i] = i + 1;
    }

    vector<vector<int> > result = subsets(array);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}