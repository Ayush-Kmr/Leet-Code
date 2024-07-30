class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        stack<char>st;
        int count =0;
        for(int i=0; i<n; i++){
            if(st.empty()) st.push(s[i]);
            else if(s[i] == 'a'){
                if(st.top() == 'b') {
                    st.pop();
                    count++;
                }
            }
            else st.push(s[i]);
        }
        return count;
    }
};