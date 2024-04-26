class Solution {
public:
    int n;
    int solve(vector<vector<int>>& matrix,int row, int col,vector<vector<int>>&dp){
        if(row == n-1) return matrix[row][col];
        int minSum = INT_MAX;
        if(dp[row][col]!= -1) return dp[row][col];
        for(int nextCol =0; nextCol<n; nextCol++){
            if(nextCol!= col){
                minSum = min(minSum,solve(matrix,row+1,nextCol,dp));
            }
        }
        dp[row][col] = minSum + matrix[row][col];
        return dp[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int result = INT_MAX;
        for(int col =0; col<n; col++){
            result = min(result,solve(matrix,0,col,dp));
     }
        return result;
    }
};
