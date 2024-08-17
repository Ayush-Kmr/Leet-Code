class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int mini = arr[0][0];
        int maxi = arr[0].back();
        int maxDistance = 0;
        for(int i=1; i<arr.size(); i++){
            maxDistance = max(maxDistance, abs(arr[i].back() - mini));
            maxDistance = max(maxDistance, abs(maxi - arr[i][0]));
            mini = min(mini,arr[i][0]);
            maxi = max(maxi,arr[i].back());
        }
        return maxDistance;
    }
};