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
        
        
//      Another logic   
        // int open=0;
        // int count =0;
        // for(auto i:s){
        //     if(i=='[') open++;
        //     else open--;
        //     count = min(count,open);
        // }
        // return (abs(count)+1)/2;
    }
};



