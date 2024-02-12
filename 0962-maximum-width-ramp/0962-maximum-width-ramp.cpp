class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans  = 0;
        
        for(int i=0; i<nums.size()-1; i++){
            for(int j=nums.size()-1; j>=i; j--){
                if(nums[i]<= nums[j]){
                    int res = j - i;
                    ans = max(ans,res);
                    break;
                }
            }
        }
        return ans;
    }
};