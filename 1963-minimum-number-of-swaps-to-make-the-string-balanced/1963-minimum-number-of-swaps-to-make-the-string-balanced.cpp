class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int count =0;
        for(auto i:s){
            if(i=='[') st.push(i);
            else if(st.empty()) count++;
            else st.pop();
        }
        if(!st.empty()) count++;
        return count/2;
    }
};
