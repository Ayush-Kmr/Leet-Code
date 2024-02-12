class Solution {
public:
    
//     Top Down
    int solve(vector<int>&v , int i , int j,vector<vector<int>>&dp){
//         Base Case
        if(i+1 == j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini =INT_MAX;
         for(int k = i+1; k<j; k++){
             mini = min(mini, v[i]*v[j]*v[k] + solve(v,i,k,dp) + solve(v,k,j,dp));
         }
        return dp[i][j] = mini;
    }
    
    
//     Bottom UP
    int solveTab(vector<int>&v){
        int n =v.size();
    vector<vector<int>>dp(v.size()+1, vector<int>(v.size()+1, 0));
        for(int i=n-1; i>=0; i--){
            for(int j =i+2; j<=n-1; j++){
                int mini =INT_MAX;
         for(int k = i+1; k<j; k++){
             mini = min(mini, v[i]*v[j]*v[k] + dp[i][k]+ dp[k][j]);
         }
         dp[i][j] = mini;
            }
        }
        return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        // vector<vector<int>>dp(values.size()+1, vector<int>(values.size()+1, -1));
        // return solve(values, 0, values.size()-1,dp);
        
        return solveTab(values);
    }
};