#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    int len1 = s1.size();
    int len2 = s2.size();

    if (len1 != len2) {
        cout << 3 << endl;
        return 0;
    }

    int state = 1;

    for (int i = 0; i < len1; i++) {
        int x1 = (s1[i] - 'a') / 9;
        int y1 = (s1[i] - 'a') % 9;
        int x2 = (s2[i] - 'a') / 9;
        int y2 = (s2[i] - 'a') % 9;

        if (abs(x1 - x2) > 1 || abs(y1 - y2) > 1) {
            cout << 3 << endl;
            return 0;
        }    

        if (abs(x1 - x2) == 1 || abs(y1 - y2) == 1)
            state = 2;
    }

    cout << state << endl;

    return 0;
}