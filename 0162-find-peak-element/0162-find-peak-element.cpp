class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                return i;
            }
        }
        return {};
    }
};