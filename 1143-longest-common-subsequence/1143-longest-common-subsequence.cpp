class Solution {
public:
//     Top Down Approach
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i == s1.length() || j == s2.length()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int res =0;
        if (s1[i] == s2[j]) {
            res = 1 + solve(s1, s2, i + 1, j + 1, dp);
        } else {
            int op1 = solve(s1, s2, i + 1, j, dp);
            int op2 = solve(s1, s2, i, j + 1, dp);
            res = max(op1, op2);
        }

        return dp[i][j] = res;
    }

    
//     Bottom Up Approach
    int solveTab(string s1, string s2){
        int n = s1.length()-1;
        int m = s2.length()-1;
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
        for(int i=n; i>=0; i--){
            for(int j =m; j>=0; j--){
        int res =0;
        if (s1[i] == s2[j]) {
            res = 1 + dp[i+1][j+1];
        } else {
            int op1 = dp[i+1][j];
            int op2 = dp[i][j+1];
            res = max(op1, op2);
        }

          dp[i][j] = res;
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.length();
        // int m = text2.length();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return solve(text1, text2, 0, 0, dp);
        
        return solveTab(text1,text2);
        
    }
};
