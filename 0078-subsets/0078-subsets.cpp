class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,{},nums);
        return ans;
    }
    void solve(int p, vector<int>store, vector<int>nums){
        if(p>=nums.size()){
            ans.push_back(store);
            return;
        }
        solve(p+1,store,nums);
        store.push_back(nums[p]);
        solve(p+1,store,nums);
    }
};
