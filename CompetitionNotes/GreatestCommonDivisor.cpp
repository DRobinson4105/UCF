#include <iostream>

using namespace std;

int euclidsTheorem(int num1, int num2) {
    int temp;

    // Make num1 the lower number
    if (num1 < num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    while (num2 > 0) {
        temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }

    return num1;
}

int recursive(int num1, int num2) {
    if (num2 == 0)
        return num1;

    return recursive(num2, num1 % num2);
}

int gcd(int num1, int num2) {
    return euclidsTheorem(num1, num2);
}

int lcm(int num1, int num2) {
    return num1 * num2 / gcd(num1, num2);
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << endl;
}