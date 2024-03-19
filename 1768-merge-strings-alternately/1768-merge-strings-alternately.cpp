class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int n = word1.length();
        int m = word2.length();
        int i=0,j=0;
        while(i<n && i<m){
            ans +=word1[i++];
            ans +=word2[j++];
        }
        while(i<n) ans+=word1[i++];
        while(j<m) ans+=word2[j++];
        
        return ans;
    }
};