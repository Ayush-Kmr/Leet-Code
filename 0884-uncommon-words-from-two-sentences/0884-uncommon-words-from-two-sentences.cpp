class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp;
        vector<string> ans;
        string temp = "";

        // Process first sentence
        for (char c : s1) {
            if (c == ' ') {
                if (!temp.empty()) {
                    mp[temp]++;
                    temp = "";
                }
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) mp[temp]++;

        temp = "";

        // Process second sentence
        for (char c : s2) {
            if (c == ' ') {
                if (!temp.empty()) {
                    mp[temp]++;
                    temp = "";
                }
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) mp[temp]++;

        // Collect uncommon words
        for (const auto& entry : mp) {
            if (entry.second == 1) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};
