class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int spaceIdx = 0;
        int n = spaces.size();
        for (int i = 0; i < s.length(); ++i) {
            if (spaceIdx < n && i == spaces[spaceIdx]) {
                ans += " ";
                ++spaceIdx;
            }
            ans += s[i];
        }
        return ans;
    }
};
