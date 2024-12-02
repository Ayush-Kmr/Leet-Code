class Solution {
public:
    int isPrefixOfWord(string s, string sw) {
        int n = s.size();
        int m = sw.size();
        int i = 0, count = 1;

        while (i < n) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                int j = 0;
                while (j < m && i + j < n && s[i + j] == sw[j]) {
                    j++;
                }
                if (j == m) return count;
            }
            if (s[i] == ' ') count++;
            i++;
        }

        return -1;
    }
};
