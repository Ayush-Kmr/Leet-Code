class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        unordered_set<int>rs;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    rs.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            rs.insert(st.top());
            st.pop();
        }
        string ans ="";
        for(int i=0; i<s.length(); i++){
            if(rs.find(i) == rs.end()){
                ans+=s[i];
            }
            else{
                rs.erase(i);
            }
        }
        return ans;
    }
};