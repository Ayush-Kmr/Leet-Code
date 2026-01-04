class Solution {
public:
    void solve(int index,vector<vector<int>>&ans, vector<int>& nums, vector<int>temp){
        ans.push_back(temp);
        for(int i=index; i<nums.size(); i++){
            if(i>index && nums[i] == nums[i-1])continue;
            temp.push_back(nums[i]);
            solve(i + 1, ans, nums, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0, ans, nums, temp);
        return ans;
    }
};