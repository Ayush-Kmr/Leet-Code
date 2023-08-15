class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int value;
       // int i=0;
        for(int j=0; j<n; j++){
            if(nums[j]!=j){
                // value=nums[i]-1;
                // cout<<value;
                return j; 
            }
        }
        return n;
    }
};