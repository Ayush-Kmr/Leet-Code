class Solution {
public:
    int longestIdealString(string s, int k) {
     vector<int> dp(26, 0);
    int maxLen = 0;

    for (char c : s) {
        int curr = c - 'a';
        int prev = max(0, curr - k);
        int next = min(25, curr + k);
        int localMax = 0;
        for (int i = prev; i <= next; ++i) {
            localMax = max(localMax, dp[i]);
        }
        dp[curr] = localMax + 1;
        maxLen = max(maxLen, dp[curr]);
    }

    return maxLen;
    }
};
