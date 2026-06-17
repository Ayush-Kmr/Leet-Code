class Solution {
public:
    void solve(int index, int n, vector<int>& candidates, int target,
               vector<vector<int>>& ans, vector<int> temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (index == n)
            return;
        for (int i = index; i < n; i++) {
            if (candidates[i] > target)
                return;
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            temp.push_back(candidates[i]);
            solve(i + 1, n, candidates, target - candidates[i], ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, n, candidates, target, ans, temp);
        return ans;
    }
};