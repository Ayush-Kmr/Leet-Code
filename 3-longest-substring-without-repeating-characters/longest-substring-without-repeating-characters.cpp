class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n = s.length();
        int ans = 0;
        int i=0, j=0;
        while(i<n){
            mp[s[i]]++;
            if(mp[s[i]] <= 1)ans = max(ans, i-j+1);
            else{
                while(mp[s[i]]>=2){
                    mp[s[j]]--;
                    j++;
                }
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};