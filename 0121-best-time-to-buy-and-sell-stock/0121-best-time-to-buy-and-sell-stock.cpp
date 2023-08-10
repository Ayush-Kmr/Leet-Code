class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size()-1;
        int m=INT_MAX;
        int maax=0;
        int profit=0;
        for(int i=0; i<=n; i++){
             m=min(m,prices[i]);
            profit=prices[i]-m;
            maax=max(maax,profit);
            
        }
        return maax;
    }
};