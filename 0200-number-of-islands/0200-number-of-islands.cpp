class Solution {
public:
    
    bool check(int i, int j, int  row, int col){
        return (i>=0 && i<row && j>=0 && j<col);
    }
    void find(vector<vector<char>>& grid,int i, int j){
        int row = grid.size();
        int col = grid[0].size();
        int val = grid[i][j];
        if(val == '0') return;
        grid[i][j] = '0';
        if(check(i-1,j,row,col)) find(grid,i-1,j);
        if(check(i+1,j,row,col)) find(grid,i+1,j);
        if(check(i,j+1,row,col)) find(grid,i,j+1);
        if(check(i,j-1,row,col)) find(grid,i,j-1);
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans =0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    find(grid,i,j);
                     ans ++;
                }
            }
        }
        return ans;
    }
};