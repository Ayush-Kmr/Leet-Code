class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,nums,ans);
        return ans;
    }
    void solve(int k, vector<int>&nums, vector<vector<int>>&ans){
        if(k>=nums.size()){
            ans.push_back(nums);
            return;}
        for(int i=k; i<nums.size(); i++){
            swap(nums[k],nums[i]);
            solve(k+1, nums,ans);
            swap(nums[k], nums[i]);
        }
    }
    
};