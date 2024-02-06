class Solution {
public:
    
    void solve(int index, string s,set<string>st, vector<string> &result, string temp){
        if(index == s.length()){
            temp.pop_back();
            result.push_back(temp);
            return ;
        }
        string substring = "";
        for(int i =index; i<s.length(); i++){
            substring.push_back(s[i]);
            
            if(st.count(substring))
                solve(i+1,s,st,result,temp+substring+" ");
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        vector<string>result;
        
        for(auto str: wordDict){
            st.insert(str);
        }
        string temp = "";
        solve(0,s,st,result,temp);
        return result;
    }
};