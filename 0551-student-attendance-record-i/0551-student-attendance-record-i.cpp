class Solution {
public:
    bool checkRecord(string s) {
        int n=s.size()-1;
        int a=0;
        int l=0;
        for(int i=0; i<=n; i++){
            if(s[i]=='A')
                a++;
            if(s[i]=='L'){
                l++;}
            else{
                l=0;
            }
            if(a>1 || l>=3)
            return 0;
        }
        
        
            return 1;
    }            
};