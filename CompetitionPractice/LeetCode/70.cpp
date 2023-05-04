/*
Solve nth term in a fibonacci sequence

1. Start with n1 at 1, n2 at 2 and track a sum starting at 0
2. Until nth term:
    - Add n1 and n2 to sum
    - Set n1 to n2
    - Set n2 to sum
3. Sum will be the nth term
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        // Start first two terms at 1 and 2
        int n1 = 1;
        int n2 = 2;
        int sum;

        for (int i = 3; i <= n; i++) {
            // Add next term in sequence and move n1 and n2 to next term
            sum = n1 + n2;
            n1 = n2;
            n2 = sum;
        }

        return sum;
    }
};