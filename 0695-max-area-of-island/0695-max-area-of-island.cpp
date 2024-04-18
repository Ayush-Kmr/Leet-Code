class Solution {
public:
    bool check(int i, int j, int row, int col){
        return (i>=0 && i<row && j>=0 && j<col);
    }
    int find(vector<vector<int>>& grid, int i, int j){
        int row = grid.size();
        int col = grid[0].size();
        int val = grid[i][j];
        if(val == 0) return 0;
        int ans =1;
        grid[i][j] = 0;
        if(check(i-1,j,row,col)) ans+=find(grid,i-1,j);
        if(check(i+1,j,row,col)) ans+=find(grid,i+1,j);
        if(check(i,j+1,row,col)) ans+=find(grid,i,j+1);
        if(check(i,j-1,row,col)) ans+=find(grid,i,j-1);
        
        return ans;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area =0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) area = max(area,find(grid,i,j));
            }
        }
        return area;
    }
};