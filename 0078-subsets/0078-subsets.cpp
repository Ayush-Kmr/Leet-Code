class Solution {
public:
    
       void helper(vector<int>nums,int pos, vector<int>&temp, vector<vector<int>>&ans){
        if(pos>=nums.size()){
            ans.push_back(temp);
            return;
        }
//          Include
        temp.push_back(nums[pos]);
        helper(nums,pos+1,temp,ans);
           
//            Backtracking
        temp.pop_back();
           
//         Exclude
        helper(nums,pos+1,temp,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        helper(nums,0,temp,ans);
        return ans;
    }
};