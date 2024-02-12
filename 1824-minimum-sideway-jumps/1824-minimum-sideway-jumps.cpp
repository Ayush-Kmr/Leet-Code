class Solution {
public:
    int solve(const vector<int>& obs, int currlane, int currpos, vector<vector<int>>& dp) {
        int lastpos = obs.size() - 1;
        if (currpos == lastpos) return 0;

        // Check if the result is already computed
        if (dp[currpos][currlane] != -1) return dp[currpos][currlane];

        // Straight Check
        if (obs[currpos + 1] != currlane) {
            return dp[currpos][currlane] = solve(obs, currlane, currpos + 1, dp);
        } else {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++) {
                if (i != currlane && obs[currpos] != i) {
                    ans = min(ans, 1 + solve(obs, i, currpos, dp));
                }
            }
            return dp[currpos][currlane] = ans;
        }
    }

    int minSideJumps(vector<int>& obstacles) {
        int currpos = 0;
        int currlane = 2;

        // Initialize a 2D DP array to store intermediate results
        vector<vector<int>> dp(obstacles.size(), vector<int>(4, -1));

        return solve(obstacles, currlane, currpos, dp);
    }
};