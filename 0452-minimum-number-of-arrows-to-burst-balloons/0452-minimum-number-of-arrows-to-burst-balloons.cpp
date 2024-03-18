class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points));
        vector<int>prev = points[0];
        int count=1;
        for(int i=1; i<n; i++){
            int prevStart = prev[0];
            int prevEnd = prev[1];
            
            int currStart = points[i][0];
            int currEnd = points[i][1];
            
//             No overlapping condition
            if(prevEnd < currStart){
                count++;
                prev = points[i];
            }
//             Overlapping condition
            else{
                prev[0] = max(prevStart, currStart);
                prev[1] = min(prevEnd, currEnd);
            }
        }
        return count;
    }
};