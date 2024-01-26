class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int  n = nums.size();
        vector<int> ans(n);
        int product = 1;
        int prev= 1;
        for(int i=n-1; i>=0; i--){
            ans[i] = prev;
            prev*=nums[i];
        }
        prev=1;
        for(int i = 0; i<n; i++){
            ans[i] = ans[i]*prev;
            prev *= nums[i];
        }
        return ans;
    }
};