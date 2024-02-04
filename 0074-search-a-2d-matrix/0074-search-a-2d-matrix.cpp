class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int row = m.size();
        int col = m[0].size();

        int low= 0;
        int high = row*col-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                int mR = mid / col;
                int mC = mid % col;
                int currval = m[mR][mC];
                if(currval == target) return 1;
                else if(currval > target) high = mid-1;
                else low = mid+1;
            }
        return 0;
    }
};