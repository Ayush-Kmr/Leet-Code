class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // int value;
        // for(int j=0; j<n; j++){
        //     if(nums[j]!=j){
        //         return j; 
        
        
//         Using AP
        int sum=0;
        int n=nums.size();
       // int first=0;
        //int last=n-1;
       sum=(n*(1+n))/2;
        for(int i=0; i<n; i++){
            sum= sum-nums[i];
        }
            
        
        // return n;
            return sum;
    }
};