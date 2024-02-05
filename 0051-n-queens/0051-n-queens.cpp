class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Backward straight check
        int x=row;
        int y = col;
        while(y>=0) {
            if (board[x][y] == 'Q') return false;
            y--;
        }

    
        // Upward Diagonal Check
        x=row;
        y = col;
        while(x>=0 && y>=0) {
            if (board[x][y] == 'Q') return false;
            x--;
            y--;
        }
        
        

        // Downward Diagonal Check
         x=row;
         y = col;
        while(x<n && y>=0) {
            if (board[x][y] == 'Q') return false;
            x++;
            y--;
        }

        return true;
    }

    void solve(vector<string>& board, vector<vector<string>>& ans, int n, int col) {
        if (col == n) {
            // store answer
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col, n)) {
                // action
                board[row][col] = 'Q';

                // recursive call
                solve(board, ans, n, col + 1);

                // backtracking
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // Initialize the board with '.' for empty cells
        vector<string> board(n, string(n, '.'));  
        
        vector<vector<string>> ans;

        int col = 0;

        solve(board, ans, n, col);
        return ans;
    }
};