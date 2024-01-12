class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // set<vector<int>>st;
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i =0; i<n; i++){
            int target = -nums[i];
            int start=i+1;
            int end = n-1;
         if(i!=0 && nums[i]==nums[i-1])continue;
        while(start<end){
            if(nums[start]+nums[end]==target){
                ans.push_back({nums[i],nums[start],nums[end]});
                start++;
                end--;
                while(start<end && nums[start]==nums[start-1])start++;
                 while(start<end && nums[end]==nums[end+1])end--;
            }
            else if(nums[start]+nums[end]<=target){
                start++;
            }
            else{
                end--;
            }
        }
            
    }
        // for(auto i:st){
        //         ans.push_back(i);
        //     }
        return ans;
    }
};