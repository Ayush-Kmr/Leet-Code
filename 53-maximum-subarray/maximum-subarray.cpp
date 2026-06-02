class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0, ans =nums[0];
        for(auto i: nums){
            sum+= i;
            ans = max(ans, sum);
            if(sum<=0){
                ans = max(ans, sum);
                sum =0;
            }
        }
        return ans;
    }
};