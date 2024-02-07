class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count =0;
        for(auto i:s){
            if(i=='('){
                 st.push(i);
                 count++;
            }
            // else if(i==')' && st.empty()) count++;
            else{
                if(i==')' && !st.empty() && st.top()=='('){
                    count--;
                    st.pop();
                }
                else if(i==')' && !st.empty() && st.top()!='('){
                        count++;
                }
                else {
                    count++;
                }
            }   
        }
        return count;
    }
};