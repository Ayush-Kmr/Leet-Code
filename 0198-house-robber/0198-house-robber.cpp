class Solution {
public:
    int solve(vector<int>& nums, int i, int n, vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int include = nums[i] + solve(nums, i+2, n,dp);
        int exclude = 0 + solve(nums, i+1, n,dp);
        
        return dp[i] = max(include, exclude);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        int ans = solve(nums, 0, n,dp);
        return ans;
    }
};