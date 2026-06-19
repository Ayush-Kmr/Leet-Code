class Solution {
public:
    bool solve(int st, string &s, unordered_set<string> &dict,
               vector<int> &dp) {

        if (st == s.size()) return true;

        if (dp[st] != -1) return dp[st];

        string word = "";

        for (int i = st; i < s.size(); i++) {
            word += s[i];

            if (dict.count(word)) {
                if (solve(i + 1, s, dict, dp))
                    return dp[st] = true;
            }
        }

        return dp[st] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size(), -1);

        return solve(0, s, dict, dp);
    }
};