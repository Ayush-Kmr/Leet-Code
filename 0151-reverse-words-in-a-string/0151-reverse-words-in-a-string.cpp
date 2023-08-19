class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        string first="";
        string second="";
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                if(first.size()>0){
                    if(second.size()>0)
                        second=first+" "+second;
                    else
                        second=first;
                        first="";
                }
            }
            else{
                first=first+s[i];
            }
        }   
        return second;
    }
};