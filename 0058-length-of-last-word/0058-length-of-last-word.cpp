class Solution {
public:
    int lengthOfLastWord(string s) {
        s=" "+s;
        int n=s.size()-1;
        int ans=0;
        for(int i=n;i>=0;i--)
        {
            if(s[i]!=' ')
                ans++;
            else if(ans>0 )return ans;
        }
       return 0;
    }
};