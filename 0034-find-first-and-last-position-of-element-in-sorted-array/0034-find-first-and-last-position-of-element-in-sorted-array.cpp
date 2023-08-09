class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sp=-1;
        int ep=-1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==target){
                sp=i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i]==target){
                ep=i;
                break;
            }
        }
        return {sp,ep};
    }
};