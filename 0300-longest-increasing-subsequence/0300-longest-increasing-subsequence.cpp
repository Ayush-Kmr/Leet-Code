class Solution {
public:
    int solve(vector<int>& nums, int n, int curr, int prev, vector<vector<int>>& memo) {
        if (curr == n) {
            return 0;
        }

        if (memo[curr][prev + 1] != -1) {
            return memo[curr][prev + 1];
        }

        int pick = 0, notPick = 0;

        if (prev == -1 || nums[curr] > nums[prev]) {
            pick = 1 + solve(nums, n, curr + 1, curr, memo);
        }

        notPick = solve(nums, n, curr + 1, prev, memo);

        memo[curr][prev + 1] = max(pick, notPick);
        return memo[curr][prev + 1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1)); // Memoization table
        int prev = -1;
        int curr = 0;
        int ans = solve(nums, n, curr, prev, memo);

        return ans;
    }
};