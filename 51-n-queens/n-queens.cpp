class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string>&board){
        int x = row;
        int y = col;

        // Straight backward check
        while(y>=0){
            if(board[x][y] == 'Q') return false;
            y--;
        }

        x = row;
        y = col;

        // Left Diagnoal Check
        while(x>=0 && y>= 0){
            if(board[x][y] == 'Q') return false;
            x--;
            y--;
        }

        x = row;
        y = col;

       // Right Diagonal Check
        while(x<n && y>=0){
            if(board[x][y] == 'Q') return false;
            x++;
            y--;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans, vector<string>&board, int n, int col){
        if(col >= n){
            ans.push_back(board);
            return;
        }
        for(int row =0; row<n; row++){
            if(isSafe(row, col, n, board)){
                board[row][col] = 'Q';
                solve(ans, board, n, col+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n, string(n, '.'));
        int col =0;
        solve(ans, board, n, col);
        return ans;
    }
};