class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int>mp;
        int count = 0, ans =0;
        for(auto i:nums) mp[i]++;
        for(auto &i:mp){
            if(mp.find(i.first - 1) != mp.end()) count++;
            else {
                ans = max(ans, count);
                count = 1;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};