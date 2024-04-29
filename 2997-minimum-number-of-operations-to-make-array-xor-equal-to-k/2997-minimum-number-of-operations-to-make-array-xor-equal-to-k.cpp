class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=0;
        for(int i=0; i<nums.size(); i++){
            x^=nums[i];
        }
        if(x==k) return 0;
        int ans = x^k;
        return __builtin_popcount(ans);
        
    }
};