class Solution {
public:
    void solve(vector<vector<int>>& matrix, int row, int col, vector<int>& ans) {
        int x = 0;
        int y = 0;

        while (x < row && y < col) {
            // Traverse right
            for (int i = y; i < col; i++) {
                ans.push_back(matrix[x][i]);
            }
            x++;

            // Traverse down
            for (int i = x; i < row; i++) {
                ans.push_back(matrix[i][col - 1]);
            }
            col--;

            // Traverse left
            if (x < row) {
                for (int i = col - 1; i >= y; i--) {
                    ans.push_back(matrix[row - 1][i]);
                }
                row--;
            }

            // Traverse up
            if (y < col) {
                for (int i = row - 1; i >= x; i--) {
                    ans.push_back(matrix[i][y]);
                }
                y++;
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) {
            return ans;
        }

        int row = matrix.size();
        int col = matrix[0].size();
        solve(matrix, row, col, ans);

        return ans;
    }
};
