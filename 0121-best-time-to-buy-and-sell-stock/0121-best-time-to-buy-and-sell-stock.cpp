class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size()-1;
        int miin=INT_MAX;
        int max_value=0;
        for(int i=0; i<=n; i++){
            int miin=min(prices[i],miin);
            // cout<<miin;
            int profit=prices[i]-miin;
            max_value=max(max_value,profit);
        }
        return max_value;
    }
};