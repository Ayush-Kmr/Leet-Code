class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n = s.size();
        if(n<=1) return n;
        int thres = 0;
        int ans = 1;
        int count =0;
        for(int i =0; i< n; i++){
            if(mp.count(s[i])== 0 || mp[s[i]]< thres){
                count++;
                mp[s[i]] = i;
            }
            else {
                ans = max(ans,count);
                count = i - mp[s[i]];
                thres =mp[s[i]]; 
                mp[s[i]]=i;
                
            }
        }
        return max(ans,count);
    }
};