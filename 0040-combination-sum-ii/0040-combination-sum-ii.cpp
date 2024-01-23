class Solution {
public:
    void solve(vector<int>& arr, int index, vector<int>& temp, vector<vector<int>>& ans, int currsum, int target) {
        if (currsum == target) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1]) {
                continue; // Skip duplicate elements to avoid duplicate combinations
            }

            if (currsum + arr[i] <= target) {
                temp.push_back(arr[i]);
                solve(arr, i+1, temp, ans, currsum + arr[i], target);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int currsum = 0;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, temp, ans, currsum, target);
        return ans;
    }
};
