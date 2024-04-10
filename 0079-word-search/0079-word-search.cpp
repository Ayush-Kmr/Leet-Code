class Solution {
public:
    bool isValidPath(int row,int col, int i, int j){
        if(i<row && i>=0 && j>=0 && j<col) return true;
        return false;
    }
    bool solve(vector<vector<char>>&board, string word, int i , int j, int pos){
        if (pos == word.size()) return true;
        if(board[i][j] == ' ') return false;
        int row = board.size();
        int col = board[0].size();
        if(board[i][j] != word[pos]) return false;
        
        
        char temp = board[i][j];
        board[i][j] = ' ';
        bool ans = false;
        if(isValidPath(row,col,i+1,j)) ans |= solve(board,word,i+1,j,pos+1);
        if(isValidPath(row,col,i-1,j)) ans |= solve(board,word,i-1,j,pos+1);
        if(isValidPath(row,col,i,j+1)) ans |= solve(board,word,i,j+1,pos+1);
        if(isValidPath(row,col,i,j-1)) ans |= solve(board,word,i,j-1,pos+1);
        if(temp == word[pos]) ans |= solve(board,word,i,j,pos+1);
        board[i][j] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(solve(board, word, i ,j, 0)) return true;
            }
        }
        return false;
    }
};