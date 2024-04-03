class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    bool isSafe(int x, int y, vector<vector<char>>& board) {
        return (x>=0 and y>=0 and x<board.size() and y<board[0].size());
    }
    
    bool wordExists(vector<vector<char>>& board, string word, int i, int j, int pos) {
        if (board[i][j] != word[pos])
            return false;
        
        if (pos+1 == word.size())
            return true;
        
        char temp = board[i][j];
        board[i][j] = ' ';
        for (int k = 0; k < 4; k++) {
            int x = dx[k] + i;
            int y = dy[k] + j;
            if (isSafe(x, y, board) and wordExists(board, word, x, y, pos+1))
               return true;
        }
        board[i][j] = temp;
        return false;
    }    
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(wordExists(board, word, i, j, 0))
                   return true;
            }
        }
        return false;
    }
};
