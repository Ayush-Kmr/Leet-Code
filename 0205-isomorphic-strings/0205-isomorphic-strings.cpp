class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s1 = s.length();
        int t1 = t.length();
        if(s1!=t1)return false;
        unordered_map<char,char>first;
        unordered_map<char,char>second;
        for(int i =0; i<s1; i++){
            char c1 = s[i];
            char c2 = t[i];
            if(first.count(c1) && first[c1]!=c2)return false;
            if(second.count(c2) && second[c2]!=c1)return false;
            
            first[c1] = c2;
            second[c2] = c1;
        }
        return true;
    }
};