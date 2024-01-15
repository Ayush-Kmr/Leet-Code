class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int>freq(128);
        int distinct=0;
        int count =0;
        int start =0, end=0, ans=1; 
        if(s.empty()){
            return 0;
        }
        while(end<n){
            if(freq[s[end]]==0) distinct++;
            freq[s[end]]++;
        while(distinct < (end-start+1)){
            freq[s[start]]--;
            if(freq[s[start]]==0) distinct--;
            start++;
        }
            ans= max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};