class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int n1 = 1;
        int n2 = 2;
        int sum;

        for (int i = 3; i <= n; i++) {
            sum = n1 + n2;
            n1 = n2;
            n2 = sum;
        }

        return sum;
    }
};