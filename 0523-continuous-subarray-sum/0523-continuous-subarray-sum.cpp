class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum =0;
        int remainder =0;
        int n = nums.size();
        mp[0] = -1;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            remainder = sum%k;
            
            if(mp.find(remainder)!=mp.end()){
                if(i - (mp[remainder]) >=2 )return true; 
            }
            else{
                mp[remainder] = i;
            }
        }
        return false;
    }
};