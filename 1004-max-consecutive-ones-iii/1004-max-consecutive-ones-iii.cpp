class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int zero=0;
        int win=0;
        int p=0;
        for(int i: nums)
        {
            zero+=i^1;
            if(zero<=k)win++;
            else zero-=nums[p++]^1;
            
            
        }
        return win;
        
    }
};