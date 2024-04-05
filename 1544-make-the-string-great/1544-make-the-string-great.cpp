class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            if(st.empty()) st.push(s[i]);
            else{
                char c1 = st.top();
                if(abs(c1-s[i]) == 32){
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty()){
            char value = st.top();
            st.pop();
            ans+=value;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};