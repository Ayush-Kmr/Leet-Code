#include <vector>

class Solution {
public:
    void solve(vector<vector<int>>& matrix, int row, int col, vector<int>& ans, int z) {
        // Traverse the top row
        for (int i = z; i < col - z; i++) {
            ans.push_back(matrix[z][i]);
        }

        // Traverse the rightmost column
        for (int i = z + 1; i < row - z; i++) {
            ans.push_back(matrix[i][col - z - 1]);
        }

        // Traverse the bottom row if it's different from the top row
        if (z < row - z - 1) {
            for (int i = col - z - 2; i >= z; i--) {
                ans.push_back(matrix[row - z - 1][i]);
            }
        }

        // Traverse the leftmost column if it's different from the rightmost column
        if (z < col - z - 1) {
            for (int i = row - z - 2; i > z; i--) {
                ans.push_back(matrix[i][z]);
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int row = matrix.size();
        if (row == 0) {
            return ans;
        }
        int col = matrix[0].size();
        if (col == 0) {
            return ans;
        }

        for (int i = 0; i <= min(row - 1, col - 1) / 2; i++) {
            solve(matrix, row, col, ans, i);
        }

        return ans;
    }
};
