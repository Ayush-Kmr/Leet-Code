class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum=0, ans=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(nums[i]==0) sum=0;
            ans=max(ans,sum);
        }
        return ans;
    }
};