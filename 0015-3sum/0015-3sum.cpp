class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i =0; i<n-1; i++){
            int target = -nums[i];
            int start=i+1;
            int end = n-1;
            
        while(start<end){
            if(nums[start]+nums[end]==target){
                st.insert({nums[i],nums[start],nums[end]});
                start++;
                end--;
            }
            else if(nums[start]+nums[end]<target){
                start++;
            }
            else{
                end--;
            }
        }
            
    }
        for(auto i:st){
                ans.push_back(i);
            }
        return ans;
    }
};