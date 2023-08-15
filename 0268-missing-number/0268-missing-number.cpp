class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
       sum=(n*(1+n))/2;
        for(int i=0; i<n; i++){
            sum= sum-nums[i];
        }
            
        
            return sum;
    }
};