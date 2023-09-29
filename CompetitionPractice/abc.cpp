#include <iostream>
#include <vector>

using namespace std;

#define RANGE (10^9 + 7)
vector<int> stored(1 << 21, -1);

int computeIndex(u_int8_t p, u_int8_t s1, u_int8_t s2) {
    return (p << 14) + (min(s1, s2) << 7) + max(s1, s2);
}

int compute(int p, int s1, int s2) {
    if (p == 0 && s1 == 0 && s2 == 0) return 1;

    int self = computeIndex(p, s1, s2);
    int storedSelf = stored[self];
    if (storedSelf != -1)
        return storedSelf;

    long result = 0;
    if (s1 > 0) {
        result += compute(s1 - 1, min(p, s2), max(p, s2));
    }

    if (s2 > 0) {
        result += compute(s2 - 1, min(p, s1), max(p, s1));
    }

    return stored[self] = result % RANGE;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int result = 0;
    if (a > 0)
        result += compute(a - 1, min(b, c), max(b, c));
    if (b > 0)
        result += compute(b - 1, min(a, c), max(a, c));
    if (c > 0)
        result += compute(c - 1, min(b, a), max(b, a));
    
    cout << result % RANGE << endl;
    return 0;
}