class Solution {
public:
    int lengthOfLastWord(string s) {
        bool foundNonSpace = 0;
        int n = s.length();
        int count=0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            count++;
            foundNonSpace = 1; 
        } else {
            if (foundNonSpace) {
                return count;
            }
        }
    }

    return count; 
    }
};