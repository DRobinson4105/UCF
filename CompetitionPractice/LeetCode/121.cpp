#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowestPrice = INT_MAX;
        int overallProfit = 0;
        int currentProfit = 0;
        int numPrices = prices.size();

        for (int i = 0; i < numPrices; i++) {
            if (prices[i] < lowestPrice)
                lowestPrice = prices[i];

            currentProfit = prices[i] - lowestPrice;

            if (currentProfit > overallProfit)
                overallProfit = currentProfit;
        }

        return overallProfit;
    }
};