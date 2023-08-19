class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        string t="";
        string st="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') {
               if(st.size()>0 )
               { 
                if(t.size()>0)
                    t=st+" "+t;
                else 
                    t=st;
                st="";
                }
            }
                else st=st+s[i];
        
        }

        return t ;
        }
};