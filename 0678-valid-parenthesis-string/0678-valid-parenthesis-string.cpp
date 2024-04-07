class Solution {
public:
    bool checkValidString(string s) {
        int open =0;
        int total =0;
        for(auto ch:s){
            if(ch == '('){
                open++;
                total++;
            }
            else if(ch == ')'){
                open--;
                total--;
            }
//             Found "*"
            else{
                open--;
                total++;
            }
        if(open < 0) open =0;
        if(total <0) return false;
        }
        
        
        return open==0;
    }
};