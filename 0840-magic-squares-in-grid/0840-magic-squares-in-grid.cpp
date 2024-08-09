class Solution {
public:
    int count = 0;

    void helper(int i, int j, vector<vector<int>>& grid, int n, int m) {
        if (i + 2 < n && j + 2 < m) {
            vector<int> values;
            set<int> unique_values;
            int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];

            // Check rows
            for (int r = 0; r < 3; ++r) {
                int row_sum = 0;
                for (int c = 0; c < 3; ++c) {
                    int val = grid[i + r][j + c];
                    row_sum += val;
                    values.push_back(val);
                    unique_values.insert(val);
                }
                if (row_sum != sum) return;
            }

            // Check columns
            for (int c = 0; c < 3; ++c) {
                int col_sum = 0;
                for (int r = 0; r < 3; ++r) {
                    col_sum += grid[i + r][j + c];
                }
                if (col_sum != sum) return;
            }

            // Check diagonals
            if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != sum) return;
            if (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != sum) return;

            // Check if all numbers are distinct and from 1 to 9
            if (unique_values.size() == 9 && all_of(values.begin(), values.end(), [](int x) { return x >= 1 && x <= 9; })) {
                count++;
            }
        }
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                helper(i, j, grid, n, m);
            }
        }
        return count;
    }
};
