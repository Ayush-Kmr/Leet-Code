class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size()-1;
        int j=0;
        for(int i=0; i<=n; i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j++]);
            }
        }
    }
};