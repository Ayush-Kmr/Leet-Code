class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int value=0;
        for(int i=n-1; i>0; i--)
            if(nums[i]>nums[i-1])
            {
                value=i-1;
                break;
            }
        for(int j=n-1; j>0; j--)
            if(nums[value]<nums[j])
            {
                swap(nums[value],nums[j]);
                reverse(nums.begin()+value+1,nums.end());
                return;
            }
        
        reverse(nums.begin(),nums.end());
    }
};