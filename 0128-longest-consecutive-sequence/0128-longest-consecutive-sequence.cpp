class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        int n =  nums.size();
        if(!n) return 0;
       
        for(auto i:nums){
            mp[i]++;
        }
        int count =1;
        int result =1;
        for(auto i:mp){
        
            if(mp[i.first-1])count++;
            else count=1;
            
            result=max(result,count);
            
        }

      
      
        return max(result,count);
    }
};