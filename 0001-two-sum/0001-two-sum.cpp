class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> ans;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int comp  = target-nums[i];
            if(ans.count(comp)) return {ans[comp],i};
            ans[nums[i]]= i;            
        }
        return {  };
    }
};