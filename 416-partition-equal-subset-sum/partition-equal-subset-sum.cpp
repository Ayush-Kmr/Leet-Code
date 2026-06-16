class Solution {
public:
bool solve(int idx, int target, vector<int>& nums,vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (idx == nums.size() || target < 0) return false;

    if (dp[idx][target] != -1) return dp[idx][target];

    bool take = solve(idx + 1, target - nums[idx], nums, dp);
    bool notTake = solve(idx + 1, target, nums, dp);
    
    return dp[idx][target] = take || notTake;
}
    bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    int target = sum / 2;
    vector<vector<int>> dp(nums.size(),vector<int>(target + 1, -1));
    return solve(0, target, nums, dp);
    }
};