class Solution {
public:
    int solve(vector<int>& nums, int n, int curr, int prev, vector<int>& memo) {
        if (curr == n) {
            return 0;
        }

        int memoIndex = curr * n + prev + 1;
        if (memo[memoIndex] != -1) {
            return memo[memoIndex];
        }

        int pick = 0, notPick = 0;

        if (prev == -1 || nums[curr] > nums[prev]) {
            pick = 1 + solve(nums, n, curr + 1, curr, memo);
        }

        notPick = solve(nums, n, curr + 1, prev, memo);

        memo[memoIndex] = max(pick, notPick);
        return memo[memoIndex];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n * n + 1, -1); // Memoization array
        int prev = -1;
        int curr = 0;
        int ans = solve(nums, n, curr, prev, memo);

        return ans;
    }
};
