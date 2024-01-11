class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int low=0;
        int high=n;
        while(low<high){
            int mid = low + (high-low)/2;
            if((mid%2==0 && nums[mid]==nums[mid+1])|| (mid%2==1 && nums[mid]==nums[mid-1]))
                low=mid+1;
            
            else
                high=mid;
            
        }
    return nums[low];}
    
};