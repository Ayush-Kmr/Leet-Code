class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool>mp;
        int count = 0;
        int ans =0;
        int n =s.size();
        
        for(int i=0; i<n; i++){
            for(int j =i; j<n; j++){
                if(mp.count(s[j]) == 0) {
                    mp[s[j]] = true;
                    count++;
                }
                else{
                   ans = max(ans,count);
                    count =0;
                    mp.clear();
                    break;
                }
            }
        }
        
        return max(ans,count);
    }
};