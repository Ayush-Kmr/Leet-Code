class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mid;
        int minu=nums[0];
        while(low<=high){
            mid=low+(high-low)/2;
            minu=min(nums[mid],minu);
            if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else if(nums[mid]==nums[high]){
                high--;
            }
            else{
                if(nums[mid]<nums[high]){
                high=mid-1;
                }
                else{
                    low++;
                }
        }
        }
        return minu;
    }
};