class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size()-1;
         sort(nums.begin(),nums.end());
        for(int i=n; i>=2; i--){
            if(nums[i]<nums[i-1]+nums[i-2])
                return(nums[i]+nums[i-1]+nums[i-2]);
        }
        return 0;
    }
};