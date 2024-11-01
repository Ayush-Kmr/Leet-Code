class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int count =0;
        for(int i=0; i<s.length(); i++){
            if(i == 0 || s[i] != s[i-1]) count =1;
            else count++;
            if(count<=2) ans+= s[i];
        }
        return ans;
    }
};