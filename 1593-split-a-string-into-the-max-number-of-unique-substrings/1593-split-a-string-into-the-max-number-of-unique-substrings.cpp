class Solution {
public:
    int maxUniqueSplit(string s) {
        set<string> st;
        return backtrack(s, st, 0);
    }
    
private:
    int backtrack(string& s, set<string>& st, int start) {
        if (start == s.length()) {
            return st.size();
        }

        int maxCount = 0;
        string temp = "";

        for (int end = start; end < s.length(); ++end) {
            temp += s[end];
            if (st.find(temp) == st.end()) { 
                st.insert(temp); 
                maxCount = max(maxCount, backtrack(s, st, end + 1)); 
                st.erase(temp); 
            }
        }

        return maxCount;
    }
};
