class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, min_price = prices[0];
        for(auto& sell : prices){
            profit = max(profit, sell - min_price);
            min_price = min(min_price, sell);
        }
        return profit;
    }
};
