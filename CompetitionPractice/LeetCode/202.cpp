#include <unordered_set>
#include <cmath>

using namespace std;

/*
Repeatedly replace the number by the sum of the squares of its digits
until it is a sum that it has already reached before or the sum is 1

1. Use a set to hold used sums
2. While sum is not 1
    - Calculate sum by adding the squares of its digits
    - If sum was already used, return false
    - Set n to the sum and add it to set
3. Return true if sum reaches 1
*/

class Solution {
public:
    bool isHappy(int n) {
        int sum = 2;
        unordered_set<int> used;
        
        while (sum != 1) {
            // Calculate sum
            sum = 0;
            while (n > 0) {
                sum += pow(n % 10, 2);
                n /= 10;
            }

            // If sum was already used
            if (used.count(sum) == 1)
                return false;

            // Add sum to used sums
            n = sum;
            used.insert(sum);
        }

        return true;
    }
};