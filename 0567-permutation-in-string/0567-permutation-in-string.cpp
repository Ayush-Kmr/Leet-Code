class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        unordered_map<char, int> s1Count, windowCount;
        for (char c : s1) {
            s1Count[c]++;
        }
        for (int i = 0; i < s1.length(); i++) {
            windowCount[s2[i]]++;
        }
        if (s1Count == windowCount) return true;
        for (int i = s1.length(); i < s2.length(); i++) {
            windowCount[s2[i]]++;
            char outgoing = s2[i - s1.length()];
            if (windowCount[outgoing] == 1) {
                windowCount.erase(outgoing);
            } else {
                windowCount[outgoing]--;
            }
            if (s1Count == windowCount) return true;
        }

        return false;
    }
};
