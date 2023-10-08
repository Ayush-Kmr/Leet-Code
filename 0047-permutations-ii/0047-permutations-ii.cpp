class Solution {
public:
    set<vector<int>> ans2;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(0, nums);
        vector<vector<int>> ans(ans2.begin(), ans2.end());
        return ans;
    }
    
    void solve(int k, vector<int>& nums) {
        if (k >= nums.size()) {
            ans2.insert(nums); // Insert a copy of the vector
            return;
        }
        for (int i = k; i < nums.size(); i++) {
            swap(nums[k], nums[i]);
            solve(k + 1, nums);
            swap(nums[k], nums[i]);
        }
    }
};