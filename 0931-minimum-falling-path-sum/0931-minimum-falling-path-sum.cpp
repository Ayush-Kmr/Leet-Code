class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int sum = 0;
        for(int i=1; i<n; i++){
            for(int j =0; j<n; j++){
                int minVal = matrix[i-1][j];
                if(j>0) minVal = min(minVal,matrix[i-1][j-1]);
                if(j<n-1)minVal = min(minVal,matrix[i-1][j+1]);
                    matrix[i][j] += minVal;
            }
        }
        
        int ans = INT_MAX;
        for(int j =0; j<n; j++){
            ans = min(ans, matrix[n-1][j]);
        }
        
        return ans;
    }
};