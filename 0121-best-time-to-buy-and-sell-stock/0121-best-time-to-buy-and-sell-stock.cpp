class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tobuy = prices[0];
        int profit = 0;
        for(auto i:prices){
            tobuy = min(tobuy,i);
            profit = max(i - tobuy, profit);
        }
        return profit;
    }
};