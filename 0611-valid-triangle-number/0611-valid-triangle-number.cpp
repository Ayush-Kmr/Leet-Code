class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size()-1;
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=n; i>=0; i--){
            int start=0;
            int high=i-1;
            while(start<high){
                if(nums[start]+nums[high]>nums[i]){
                    ans=ans+high-start;
                    high--;
                }
                else{
                    start++;
                }
            }
        }
        return ans;
    }
};