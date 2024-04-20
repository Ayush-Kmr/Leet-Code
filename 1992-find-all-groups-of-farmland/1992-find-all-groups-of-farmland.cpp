class Solution {
public:
    vector<vector<int>> ans;

    bool path(int i, int j, int row, int col) {
        return (i >= 0 && i < row && j >= 0 && j < col); // Corrected boundary conditions
    }

    void find(vector<vector<int>>& land, int i, int j, int& r1, int& c1, int& r2, int& c2) {
        int row = land.size();
        int col = land[0].size();
        land[i][j] = 0;

        r2 = max(r2, i);
        c2 = max(c2, j);
        if (path(i - 1, j, row, col) && land[i - 1][j] == 1) 
            find(land, i - 1, j, r1, c1, r2, c2);
        
        if (path(i + 1, j, row, col) && land[i + 1][j] == 1) 
            find(land, i + 1, j, r1, c1, r2, c2);
        
        if (path(i, j - 1, row, col) && land[i][j - 1] == 1) 
            find(land, i, j - 1, r1, c1, r2, c2);
        
        if (path(i, j + 1, row, col) && land[i][j + 1] == 1) 
            find(land, i, j + 1, r1, c1, r2, c2);
        
        r1 = min(r1, i);
        c1 = min(c1, j);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size();
        int col = land[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (land[i][j] == 1) {
                    int r1 = i, c1 = j, r2 = i, c2 = j;
                    find(land, i, j, r1, c1, r2, c2);
                    ans.push_back({r1, c1, r2, c2});
                }
            }
        }
        return ans;
    }
};
