class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int value;
        for(int j=0; j<n; j++){
            if(nums[j]!=j){
                return j; 
            }
        }
        return n;
    }
};