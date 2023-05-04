#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int sum = 2;
        int num = n;
        unordered_set<int> used;
        
        while (sum != 1) {
            sum = 0;
            while (num > 0) {
                sum += pow(num % 10, 2);
                num /= 10;
            }

            if (used.count(sum) == 1)
                break;

            num = sum;
            used.insert(sum);
        }

        return (sum == 1);
    }
};