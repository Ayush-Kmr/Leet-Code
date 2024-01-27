class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans=0;
        vector<int>right(n);
        right[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--){
            right[i] = max(prices[i],right[i+1]);
        }
        for(int i=0; i<n; i++){
            int x = right[i] - prices[i];
            ans = max(ans,x);
        }
        return ans;
    }
};