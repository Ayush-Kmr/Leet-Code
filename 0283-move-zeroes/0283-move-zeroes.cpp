class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size()-1;
        int i=0;
        for(int j=0; j<=n; j++){
            if(nums[j]!=0){
                swap(nums[j],nums[i]);
                i++;
            }
        }
    }
};