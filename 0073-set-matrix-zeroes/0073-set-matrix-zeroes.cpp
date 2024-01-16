class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        vector<int>row(n);
        vector<int>col(m);
        
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        
//    Converting column value to zero
        for(int i=0; i<n; i++){
            if(row[i]==1){
                for(int j=0; j<m; j++){
                    matrix[i][j]=0;
                }
            }
        }
        
//         Converting row value to zero
            for(int j=0; j<m; j++){
            if(col[j]==1){
                for(int i=0; i<n; i++){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};