class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for(int i=n-1; i>0; i--){
            if(nums[i-1]<nums[i]){
                index = i-1;
                break;
            }
        }
        if(index == -1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1; i>index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                reverse(nums.begin()+index+1,nums.end());
                return;
            }
        }
    }
};