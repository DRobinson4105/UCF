using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        double lo = 0;
        double hi = x;

        while ((int)hi != (int)lo)
        {
            double mid = lo + (hi - lo) / 2;

            if (mid * mid > x)
                hi = mid;
            else if (mid * mid < x)
                lo = mid;
            else
                return mid;
        }

        return (int)lo;
    }
};