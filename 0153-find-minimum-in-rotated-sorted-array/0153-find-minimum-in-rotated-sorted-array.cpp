class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low =0;
        int high =n-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            ans = min(ans,nums[mid]);
            if(nums[mid]>nums[high]){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return ans;
    }
};