class Solution {
public:
    bool isAnagram(string s, string t) {
        int m= s.length();
        int n= t.length();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(n!=m) return false;
            for(int i=0; i<n; i++){
                if(s[i]!=t[i])return false;
            }
        return true;
    }
};