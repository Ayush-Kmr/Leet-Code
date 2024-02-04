class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int r= m.size();
        int c = m[0].size();
        int row = 0;
        int col = c-1;
        while(row <r && col > -1){
            int currval = m[row][col];
            if(currval == target) return true;
            else if(currval>target) col--;
            else row++;
        }
        return false;
    }
};