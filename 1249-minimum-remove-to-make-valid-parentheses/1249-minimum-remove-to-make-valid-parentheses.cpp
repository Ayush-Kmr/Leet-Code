class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp = "";
        int open =0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' ){
                open++;
                temp +=s[i];
            }
            else if(s[i] == ')' ){
                if(open > 0){
                    open--;
                    temp += s[i];
                }
            }
            else{
                temp +=s[i];
            }
        }
        
        string final_result = "";
        for(int i=temp.length()-1; i>=0; i--){
            if(temp[i] == '(' && open > 0){
                open--;
            }
            else{
                final_result += temp[i];
            }
        }
        reverse(final_result.begin(), final_result.end());
        
        return final_result;
    }
};