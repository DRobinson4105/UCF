#include <iostream>
#include <vector>

using namespace std;

struct Heap {
    vector<int> arr;
    int size;
};

int main() {
    Heap* pq = new Heap();
    pq->arr.push_back(2);
    cout << pq->arr[0] << endl;
    cout << pq->size << endl;
}