class Solution {
public:
    void solve(int n , int curop, int curcl, int remop, int remcl, string &temp,        vector<string>&ans){
        if(remop==0 && remcl ==0){
            ans.push_back(temp);
            return;
        }
        if(remop>0){
            temp.push_back('(');
            solve(n,curop+1,curcl,remop-1,remcl,temp,ans);
            temp.pop_back();
        }
        if(remcl>remop){
            temp.push_back(')');
           solve(n,curop,curcl+1,remop,remcl-1,temp,ans);
            temp.pop_back();
    }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp ="(";
        int curop = 1;
        int curcl = 0;
        int remop = n-1;
        int remcl = n;
        solve(n,curop,curcl,remop,remcl,temp,ans);
        
        
        return ans;
    }
};