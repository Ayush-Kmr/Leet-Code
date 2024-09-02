class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalk = 0;
        for (int c : chalk) {
            totalChalk += c;
        }
        
        k %= totalChalk; // Handle cases where k is very large
        
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i;
            }
            k -= chalk[i];
        }
        
        return -1; // This line should never be reached
    }
};
