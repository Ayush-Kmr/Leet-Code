class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> board(m, vector<int>(n, 0)); 
        for (const auto& wall : walls) board[wall[0]][wall[1]] = 1; 
        for (const auto& guard : guards) board[guard[0]][guard[1]] = 2;
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (const auto& guard : guards) {
            int i = guard[0], j = guard[1];
            for (const auto& dir : directions) {
                int x = i, y = j;
                while (true) {
                    x += dir.first;
                    y += dir.second;
                    if (x < 0 || x >= m || y < 0 || y >= n || 
                        board[x][y] == 1 || board[x][y] == 2) break;
                    if (board[x][y] == 0) board[x][y] = -1;
                }
            }
        }
        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) unguardedCount++;
            }
        }
        return unguardedCount;
    }
};
