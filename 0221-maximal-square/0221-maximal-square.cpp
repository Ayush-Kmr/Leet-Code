class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j, int &maxi,vector<vector<int>>&dp){
//         base case
        int m = matrix.size();
        int n = matrix[0].size();
        if(i>=matrix.size() || j>= matrix[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int bottom = solve(matrix, i+1,j,maxi,dp);
        int diagonal = solve(matrix, i+1,j+1,maxi,dp);
        int right = solve(matrix, i , j+1,maxi,dp);
        
        if(matrix[i][j] == '1'){
            int side = min(bottom, min(diagonal,right)) + 1; 
            maxi = max(maxi,side);
            return dp[i][j] = side;
        }
        else return 0;  
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1)); 
        int maxi = 0;
        solve(matrix, 0,0,maxi,dp);
        return maxi*maxi;
    }
};