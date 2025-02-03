#include <vector>
using std::vector;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestProfit = 0, minVal = prices[0];
        for (int i = 1; i < prices.size();  ++i) {
            minVal = std::min(minVal, prices[i]);
            bestProfit = std::max(bestProfit, prices[i]-minVal);
        }
        return bestProfit;
    }
};