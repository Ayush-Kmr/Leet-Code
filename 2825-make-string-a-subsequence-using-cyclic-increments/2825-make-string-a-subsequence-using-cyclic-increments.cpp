class Solution {
public:
    char inc_char(char ch) {
         if (ch == 'z') return 'a';
         return ch + 1;
}
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            char inc_value = inc_char(str1[i]);
            if (str1[i] == str2[j] || inc_value == str2[j]) {
                i++; 
                j++; 
            } else {
                i++; 
            }
        }
        return j == m;
    }
};
