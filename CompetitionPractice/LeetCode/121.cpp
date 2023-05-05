#include <vector>
#include <limits.h>

using namespace std;

/*
Find best profit by tracking the lowest buy point
before each day and test each day as the sell point

1. Loop through each day
    - If the current price is lower than the recorded
      lowest price, replace it (the new buy point)
    - If current price is sell point and profit is 
      better than recorded best profit, replace it
2. Return best profit
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPrice = INT_MAX;
        int bestProfit = 0;
        int currentProfit = 0;
        int numPrices = prices.size();

        for (int i = 0; i < numPrices; i++)
        {
            // New lowest price was found
            if (prices[i] < lowestPrice)
                lowestPrice = prices[i];

            // Find profit using current price as sell point
            currentProfit = prices[i] - lowestPrice;

            // If better profit was found
            if (currentProfit > bestProfit)
                bestProfit = currentProfit;
        }

        return bestProfit;
    }
};