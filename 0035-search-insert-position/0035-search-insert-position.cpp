class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n =nums.size();
        int value=0;
        for(int i=0; i<n; i++){
            if(nums[i]==target){
                value=i;
            }
            else{
                if(target>=nums[i]){
                    value=i+1;
                }
            }
        }
        return value;
    }
};