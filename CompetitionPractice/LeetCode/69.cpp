using namespace std;

/*
Use a binary search to approximate the square root of x

1. Repeat process until low and high have the same whole number
    - If middle value ^ 2 is x, return middle value
    - If middle value ^ 2 is greater than target, set upper bound to middle index
    - If middle value ^ 2 is less than target, set lower bound to middle index
2. Return low value
*/

class Solution {
public:
    int mySqrt(int x) {
        double lo = 0;
        double hi = x;

        while ((int)hi != (int)lo) {
            double mid = lo + (hi - lo) / 2;

            if (mid * mid > x)
                hi = mid;
            else if (mid * mid < x)
                lo = mid;
            else
                return mid;
        }

        return lo;
    }
};