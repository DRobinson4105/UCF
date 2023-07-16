#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int num = 1;

    while ((num * a) % b != 1)
        num++;
        
    cout << (num % b) << endl;
    return 0;
}