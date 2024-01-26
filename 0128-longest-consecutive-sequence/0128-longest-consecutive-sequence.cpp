class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        int n =  nums.size();
        if(!n) return 0;
        vector<int>ans;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto i:mp){
            ans.push_back(i.first);
        }

        int count =1;
        int result =1;
        for(int i=1; i<ans.size(); i++){
            if(ans[i] == (ans[i-1]+1)) count++;
            else if(ans[i] == ans[i-1]) continue;
            else{
                result = max(count,result);
                count =1;
            }
        }
        return max(result,count);
    }
};