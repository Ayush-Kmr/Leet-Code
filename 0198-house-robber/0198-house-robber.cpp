class Solution {
public:
//     Top Down Dp
    int solve(vector<int>& nums, int i, int n, vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int include = nums[i] + solve(nums, i+2, n,dp);
        int exclude = 0 + solve(nums, i+1, n,dp);
        
        return dp[i] = max(include, exclude);
    }
    
//     Bottom Up DP
    int solve(vector<int>& nums, int N)
    {
        vector<int>dp(N+2, 0);
        for(int n = N-1; n>=0; n--){
        int include = nums[n] + dp[n+2];
        int exclude = 0 + dp[n+1];
        
        dp[n] = max(include, exclude);
            }
        return dp[0];   
    }    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n+1, -1);
        // int ans = solve(nums, 0, n,dp);
        
        int ans = solve(nums,n);
        return ans;
    }
};