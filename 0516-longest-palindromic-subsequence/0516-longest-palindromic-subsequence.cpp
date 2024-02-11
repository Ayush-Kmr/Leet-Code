class Solution {
public:
//     Top Down Approach
    int solve(string &s, string &rev, int i, int j,vector<vector<int>>&dp){
        if(i==s.length() || j==rev.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==rev[j]){
            dp[i][j] = 1 + solve(s,rev,i+1, j+1,dp);
        }
        else{
        int op1 = solve(s,rev,i+1,j,dp);
        int op2 = solve(s,rev,i,j+1,dp);
        dp[i][j] = max(op1,op2);
        }
        return dp[i][j];
    }
    
    
//     Bottom Up Approach
    int solveTab (string &s, string &rev){
        vector<vector<int>>dp(s.length()+1, vector<int>(rev.length()+1,0));
        for(int i=s.length()-1; i>=0; i--){
            for(int j =rev.length()-1; j>=0; j--){
            int res =0;
            if(s[i]==rev[j]){
            res = 1 + dp[i+1][j+1];
        }
        else{
        int op1 = dp[i+1][j];
        int op2 = dp[i][j+1];
        res = max(op1,op2);
        }
        dp[i][j] = res;
            }
        }
        return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        // vector<vector<int>>dp(s.length()+1, vector<int>(rev.length()+1,-1));
        // int ans = solve(s,rev,0,0,dp);
        
        int ans = solveTab(s,rev);
        return ans;
    }
};