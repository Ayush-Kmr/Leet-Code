class Solution {
public:
    
    int solve(string a, string b, int i , int j,vector<vector<int>>&dp){
        if(i==a.length()) return b.length()-j;
        if(j==b.length()) return a.length()-i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
//         if match
        if(a[i]==b[j]) return solve(a,b,i+1,j+1,dp);
        
//         if no match
        else{
            int insertAns= solve(a,b,i,j+1,dp);
            int deleteAns= solve(a,b,i+1,j,dp);
            int replaceAns= solve(a,b,i+1,j+1,dp);
            
            int ans =min(insertAns,min(deleteAns,replaceAns)) +1;
            
            dp[i][j] = ans;
        }
        return dp[i][j];
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1,-1));
        int ans = solve(word1,word2,0,0,dp);
        return ans;
        
    }
};