class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int rem=n%4;
        int x=n;
        if(rem==0){
            x=n;
        }
        else if(rem==1){
            x=1;
        }
        else if(rem==2){
            x=x+1;
        }
        else{
            x=0;
        }
        for(int i=0; i<n; i++){
            x^=nums[i];
            }
        return x;
    }
};