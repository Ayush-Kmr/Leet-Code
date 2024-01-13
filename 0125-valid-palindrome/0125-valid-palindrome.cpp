class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        string ans;
        for(char i:s){
            if((i>='a' && i<='z') || (i>='A' && i<='Z') || (i>='0' && i<='9')){
                if(i<'a')i+=32;
                temp+=i;
            }
        }
        ans=temp;
        cout<<temp;
        reverse(temp.begin(),temp.end());
        return ans==temp;
    }
};