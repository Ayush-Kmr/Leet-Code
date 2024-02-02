class Solution {
public:
    
       void solve(int index, vector<int>&nums, vector<vector<int>>&ans){
//            Base case
        if(index>=nums.size()){
            ans.push_back(nums);
            return;}
        for(int j=index; j<nums.size(); j++){
            swap(nums[index],nums[j]);
            solve(index+1, nums,ans);
//             Backtrack
            swap(nums[index], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,nums,ans);
        return ans;
    }
};