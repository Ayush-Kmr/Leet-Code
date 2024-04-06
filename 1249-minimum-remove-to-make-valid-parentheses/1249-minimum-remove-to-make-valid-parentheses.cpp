class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open_brac =0;
        int close_brac =0;
        string ans = "";
        int n = s.length();
//         Iterate left to right -> to elemenate extra close bracket
        for(int i=0; i<n; i++){
            if(s[i] >= 'a' && s[i]<='z'){
                ans+=s[i];
            }
            else if(s[i] == '('){
                open_brac++;
                ans+=s[i];
            }
            else if(open_brac > 0){
                open_brac--;
                ans+=s[i];
            }
        }
        
        n = ans.length();
        string result = "";
//         Iterate right to left -> to elemenate extra open bracket
        for(int i=n-1; i>=0; i--){
            if(ans[i]>='a' && ans[i]<='z'){
                result += ans[i];
            }
            else if(ans[i] == ')'){
                close_brac++;
                result += ans[i];
            }
            else if(close_brac > 0){
                close_brac--;
                result+= ans[i];
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};