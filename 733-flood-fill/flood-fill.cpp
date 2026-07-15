class Solution {
public:
    bool check(int row, int col, int i, int j){
        return (i>=0 && i<row && j>=0 && j<col);
    }
    
    void solve(vector<vector<int>>& image, int sr, int sc, int color, int originColor){
        int row = image.size();
        int col = image[0].size();
        if(!check(row,col, sr,sc)) return ;
        if(image[sr][sc] != originColor) return ;
        image[sr][sc] = color;
        
        solve(image,sr+1,sc,color,originColor);
        solve(image,sr-1,sc,color,originColor);
        solve(image,sr,sc+1,color,originColor);
        solve(image,sr,sc-1,color,originColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originColor = image[sr][sc];
        if(image[sr][sc] != color) {
            solve(image, sr,sc,color,originColor);
        }
        return image;
    }
};