class Solution {
public:
//     Top Down Approacch
    int solve(vector<vector<char>>& matrix, int i, int j, int &maxi,vector<vector<int>>&dp){
//         base case
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
    
    
//     Bottom Up approach
      void solvetab(vector<vector<char>>& matrix, int i, int j, int &maxi) {
    // base case
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int bottom = dp[i + 1][j];
            int diagonal = dp[i + 1][j + 1];
            int right = dp[i][j + 1];

            if (matrix[i][j] == '1') {
                int side = min(bottom, min(diagonal, right)) + 1;
                maxi = max(maxi, side);
                dp[i][j] = side;
            } else {
                dp[i][j] = 0;
            }
        }
    }
}
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        // int m = matrix.size();
        // int n = matrix[0].size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1)); 
        // solve(matrix, 0,0,maxi,dp);
        solvetab(matrix, 0,0,maxi);
        return maxi*maxi;
    }
};