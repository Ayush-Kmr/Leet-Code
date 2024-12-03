class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        set<int>st;
        int count =0;
        string ans = "";
        for(int i=0; i<spaces.size(); i++) st.insert(spaces[i]);
        for(int i=0; i<s.length(); i++){
            if(st.find(count) == st.end()){
               ans += s[i]; 
            }
            else{
                st.erase(count);
                ans+= " ";
                ans+= s[i];
            }
            count++;
        }
        return ans;
    }
};