#define ONESPLACE(num) ((int)(num - ((int)num/10) * 10))

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        double opposite = x;
        int numDigits = 0;
        while ((int) opposite > 0)
        {
            opposite /= 10;
            numDigits++;
        }

        opposite *= 10;

        for (int i = 0; i < numDigits / 2; i++)
        {
            if (ONESPLACE(opposite) != ONESPLACE(x))
                return false;

            opposite *= 10;
            x /= 10;
        }

        return true;
    }
};