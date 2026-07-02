class Solution {
public:
    vector<vector<int>> dp;

    int solve(string& s, int i, int j) {
        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = solve(s, i + 1, j - 1);

        return dp[i][j] = 1 + min(solve(s, i, j - 1), solve(s, i + 1, j));
    }

    int minInsertions(string s) {
        int n = s.size();

        dp.assign(n, vector<int>(n, -1));

        return solve(s, 0, n - 1);
    }
};