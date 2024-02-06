class Solution {
public:
    
    bool isSafe(int num, int row, int col, vector<vector<char>>board){
        for(int i=0; i<9; i++){
//             row check
            if(board[row][i] == num + '0' && i!=col) return false;
            if(board[i][col] == num + '0' && i!=row) return false;
            
//             3*3 sub matrix check
            if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == num + '0') return false;
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        for(int row = 0; row<9; row++){
            for(int col=0; col<9; col++){
//                 Empty cell
                if(board[row][col] == '.'){
                    for(int k =1; k<=9; k++){
                        if(isSafe(k,row,col,board)){
                            board[row][col] = k + '0';
                            bool nextsol = solve(board);
                            if(nextsol == true) return true;
//                             Backtrack
                            else board[row][col] ='.';
                    }
                }
                    
                        return false;
            }
        }
    }
        return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve (board);
    }
};