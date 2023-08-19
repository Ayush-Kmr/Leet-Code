class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int value=0;
        for(int i=n-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                value=nums[i];
                return i;
            }
        }
        return {};
    }
};