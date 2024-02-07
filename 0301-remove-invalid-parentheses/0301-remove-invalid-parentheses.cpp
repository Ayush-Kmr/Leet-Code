class Solution {
public:
    int getRemovalCount(string str){
        stack<char>st;
        for(auto i: str){
            if(i=='(') st.push(i);
            else if(i==')'){
                if(!st.empty() && st.top()=='(') st.pop();
                else st.push(')');
        }
    }
        return st.size();
    }
    
    void solve(string s, int removecnt, vector<string>&ans, map<string,bool>&mp){
        if(mp[s] == true) return ;
        else mp[s] = true;
        
       
        if(removecnt == 0){    
//             Again check for validity
            int numRemoval = getRemovalCount(s);
            if(numRemoval == 0) ans.push_back(s);
            return ;
        }
        
        for(int i=0; i<s.length(); i++){
     //             To remove the ith index in each case to check
            string leftStr = s.substr(0,i);
            string rightStr = s.substr(i+1);
            string temp = leftStr + rightStr;
//             =================================
            solve(temp,removecnt-1, ans, mp);

        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int removecnt = getRemovalCount(s);
        
        vector<string> ans;
        map<string,bool>mp;
        solve(s,removecnt,ans, mp);
        return ans;
    }
};