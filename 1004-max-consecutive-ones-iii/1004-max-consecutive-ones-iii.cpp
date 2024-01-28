class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count=0;
        int ans =0;
        int x =0,j=0;
        vector<int>temp;
        for(auto i:nums){
            if(i==0) temp.push_back(x);
            if(i==1) count++;
            else{
                if( k>0){
                    count++;
                    k--;
                } 
                else {
                    ans = max(ans,count);
                    count = x-temp[j++];
                }
                
            }
            x++;
        }
        return max(ans,count);
    }
};