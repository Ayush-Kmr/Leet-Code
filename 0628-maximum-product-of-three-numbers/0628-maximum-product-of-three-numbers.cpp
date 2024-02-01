class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n= nums.size();
        int ans =0;
        sort(nums.begin(),nums.end());
        
        ans=nums[n-1]*nums[n-2]*nums[n-3];
        ans=max(nums[0]*nums[1]*nums[n-1],ans);
        
        return max(nums[0]*nums[1]*nums[2],ans);
    }
};