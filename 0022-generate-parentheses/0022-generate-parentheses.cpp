class Solution {
public:
    void solve(string &temp, int n, int l, int r,vector<string>&ans){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(l<n){
            temp.push_back('(');
            solve(temp,n,l+1,r,ans);
            temp.pop_back();
        }
        if(r<l){
            temp.push_back(')');
            solve(temp,n,l,r+1,ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s ="";
        solve(s,n,0,0,ans);
        
        return ans;
    }
};