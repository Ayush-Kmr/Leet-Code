class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCount = 0; 
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;
            for (int i = 0; i < candidates.size(); ++i) {
                if (candidates[i] & (1 << bit)) {
                    count++;
                }
            }
            maxCount = max(maxCount, count); 
        }
        return maxCount;
    }
};
