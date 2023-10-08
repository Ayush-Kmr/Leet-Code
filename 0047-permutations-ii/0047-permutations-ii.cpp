class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans2;
        solve(0,nums,ans2);
        vector<vector<int>>ans(ans2.begin(),ans2.end());
        return ans;
    }
    void solve(int k, vector<int>& nums , set<vector<int>>& ans2){
        if(k>=nums.size()){
            ans2.insert(nums);
            return;
        }
        for(int i=k; i<nums.size(); i++){
//             To fix the index value for permutation
            swap(nums[k],nums[i]);
            solve(k+1,nums,ans2);
            swap(nums[k],nums[i]);
        }
    }
};