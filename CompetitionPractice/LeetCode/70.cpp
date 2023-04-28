/*
Solve nth term in a fibonacci sequence
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