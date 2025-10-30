class Solution {
public:
    bool check(int row, int col, vector<vector<char>>& board){

        char value = board[row][col];

        for(int i=0; i<9; i++) if(board[row][i] == value && col != i) return false;
        for(int j=0; j<9; j++) if(board[j][col] == value && row != j) return false;
        
        int boxRow = row - (row % 3);
        int boxCol = col - (col % 3);

        for(int i=boxRow; i<boxRow+3; i++){
            for(int j=boxCol; j<boxCol+3; j++){
                if(board[i][j] == value && (i!=row || j!=col))return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.' && !check(i,j, board)) return false;
            }
        }
        return true;
    }
};