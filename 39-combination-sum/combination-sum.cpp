class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>& candidates, int target, vector<int> &temp, int index){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(index == candidates.size() || target < 0) return;
        temp.push_back(candidates[index]);
        solve(ans, candidates, target - candidates[index], temp, index);
        temp.pop_back();
        solve(ans, candidates, target, temp, index+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans, candidates, target, temp, 0);
        return ans;
    }
};

