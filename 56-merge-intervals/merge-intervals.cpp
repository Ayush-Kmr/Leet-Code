class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<n; i++){
            int first = intervals[i][0];
            int second = intervals[i][1];
            if(ans.empty() || ans.back()[1] < first) ans.push_back({first, second});
            else ans.back()[1] = max(ans.back()[1], second);
        }
        return ans;
    }
};