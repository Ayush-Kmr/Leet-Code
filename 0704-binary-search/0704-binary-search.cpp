class Solution {
public:
    int search(vector<int>& nums, int target) {
        return (binary(nums, 0, nums.size()-1 ,target));
    }
    
    int binary(vector<int> nums, int low, int high , int target){
        while(low<=high)
          {  
            //return -1;
       int mid = low + (high-low)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]<target)
            low=mid+1;
        else
            high=mid-1;}
         return -1;
        
    }
};