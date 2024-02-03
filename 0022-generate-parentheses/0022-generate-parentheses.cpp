class Solution {
public:
    void solve(string temp, int n, int l, int r,vector<string>&ans){
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }
        if(l<n){
            solve(temp+'(',n,l+1,r,ans);
        }
        if(r<l){
            solve(temp+')',n,l,r+1,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve("",n,0,0,ans);
        
        return ans;
    }
};