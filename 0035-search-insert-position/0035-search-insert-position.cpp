class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n =nums.size()-1;
        int low=0;
        int high=n;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                 low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};