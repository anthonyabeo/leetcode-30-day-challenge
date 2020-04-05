#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_profit = 0;
        for(size_t i = 1; i < prices.size(); ++i) {
            int mm = prices[i] - prices[i-1];
            if(mm > 0) max_profit += mm;
        }
        
        return max_profit;
    }
};