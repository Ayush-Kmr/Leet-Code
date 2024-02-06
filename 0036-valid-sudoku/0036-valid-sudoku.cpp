class Solution {
public:
    
    bool check(vector<vector<char>>& board, int row, int col){
        char x= board[row][col];
        
//         Checking the whole row value
        for(int j=0; j<9; j++){
            if(board[row][j]==x && j!=col) return true;
        }
        
//         Checking the whole col value
        for(int i=0; i<9; i++){
            if(board[i][col]==x && i!=row) return true;
        }
        
        int i= row-(row%3);
        int j= (col/3)*3;
        
//         Checking the 3 x 3 boxes
        for(int r=i; r<i+3; r++){
            for(int c=j; c<j+3; c++){
                if(board[r][c]==x && r!=row) return true;
            }
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.' && check(board,i,j)) return false;
            }
        }
        return true;
    }
};