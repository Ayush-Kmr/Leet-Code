class Solution {
public:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s1[i - 1] == s2[j - 1]) {
            dp[i][j] = 1 + solve(s1, s2, i - 1, j - 1, dp);
        } else {
            int op1 = solve(s1, s2, i - 1, j, dp);
            int op2 = solve(s1, s2, i, j - 1, dp);
            dp[i][j] = max(op1, op2);
        }

        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(text1, text2, n, m, dp);
    }
};
