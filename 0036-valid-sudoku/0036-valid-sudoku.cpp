class Solution {
public:
    bool check(vector<vector<char>>& board,int row, int col){
        char x=board[row][col];
        
        for(int i=0; i<9; i++){
          if(board[row][i]==x && i!=col) return true;  
          
        }
         for(int j=0; j<9; j++){
            if(board[j][col]==x && j!=row) return true;     
        }
        int i=row-row%3;
        int j=(col/3)*3;
         for(int l=i; l<i+3; l++){
            for(int k=j; k<j+3; k++){
                if(board[l][k]==x && l!=row) return true;
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