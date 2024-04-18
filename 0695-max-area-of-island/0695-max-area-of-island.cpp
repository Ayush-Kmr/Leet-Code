class Solution {
public:
    bool valid(int i, int j, int col, int row){
        return i >= 0 && i < row && j >=0 && j < col;
    }

    int find(vector<vector<int>>& grid, int i, int j, int count){
        int row = grid.size();
        int col = grid[0].size();
        int val = grid[i][j];
         if(val == 0){
           
            return 0;
        }
        
        int ans = 1;
        
       
        grid[i][j] = 0; 
        
        if(valid(i-1, j, col, row)) ans+=find(grid, i-1, j, count);
        if(valid(i+1, j, col, row)) ans+=find(grid, i+1, j, count);
        if(valid(i, j+1, col, row)) ans+=find(grid, i, j+1, count );
        if(valid(i, j-1, col, row)) ans+=find(grid, i, j-1, count );
        
        // grid[i][j] = val; 
        return ans; 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                   area=max(area, find(grid, i, j, 1));
                }
            }
        }
        
        return area;
    }
};
