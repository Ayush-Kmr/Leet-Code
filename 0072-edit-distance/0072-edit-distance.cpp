class Solution {
public:
// //     Top Down Approach
//     int solve(string a, string b, int i , int j,vector<vector<int>>&dp){
//         if(i==a.length()) return b.length()-j;
//         if(j==b.length()) return a.length()-i;
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
// //         if match
//         if(a[i]==b[j])  solve(a,b,i+1,j+1,dp);
        
// //         if no match
//         else{
//             int insertAns= solve(a,b,i,j+1,dp);
//             int deleteAns= solve(a,b,i+1,j,dp);
//             int replaceAns= solve(a,b,i+1,j+1,dp);
            
//             int ans =min(insertAns,min(deleteAns,replaceAns)) +1;
            
//             dp[i][j] = ans;
//         }
//         return dp[i][j];
//     }
    
    
//     Bottom Up Approach
  int solveTab(string &a, string &b) {
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

    for (int j = 0; j < b.length(); j++) {
        dp[a.length()][j] = b.length() - j;
    }

    for (int i = 0; i < a.length(); i++) {
        dp[i][b.length()] = a.length() - i;
    }

    for (int i = a.length() - 1; i >= 0; i--) {
        for (int j = b.length() - 1; j >= 0; j--) {
            int ans = 0;

            if (a[i] == b[j]) {
                ans = dp[i + 1][j + 1];
            } else {
                int insertAns = dp[i][j + 1];
                int deleteAns = dp[i + 1][j];
                int replaceAns = dp[i + 1][j + 1];

                ans = min(insertAns, min(deleteAns, replaceAns)) + 1;
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
    
    int minDistance(string word1, string word2) {
        // vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1,-1));
        // int ans = solve(word1,word2,0,0,dp);
        
        int ans = solveTab(word1, word2);
        return ans;
        
    }
};