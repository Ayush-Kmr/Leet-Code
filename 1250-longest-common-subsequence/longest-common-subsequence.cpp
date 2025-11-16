class Solution {
public:
    int solve(string &s1, string &s2, int m, int n, int i, int j, vector<vector<int>>&dp){
        if (i == m || j == n) return 0;   
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + solve(s1, s2, m, n, i+1, j+1, dp);

        return dp[i][j] = max(
            solve(s1, s2, m, n, i+1, j, dp),
            solve(s1, s2, m, n, i, j+1, dp)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(text1, text2, m, n, 0, 0, dp);
    }
};
