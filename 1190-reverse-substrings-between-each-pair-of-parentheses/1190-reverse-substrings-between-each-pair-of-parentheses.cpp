class Solution {
public:
    string reverseParentheses(string s) {
        string temp;
        stack<string> st;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(temp);
                temp = "";
            } else if (s[i] == ')') {
                reverse(temp.begin(), temp.end());
                if (!st.empty()) {
                    temp = st.top() + temp;
                    st.pop();
                }
            } else {
                temp += s[i];
            }
        }
        
        return temp;
    }
};