class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(2 * n);
        
        // Populate the temp array with nums twice for circular behavior
        for (int i = 0; i < 2 * n; ++i) {
            temp[i] = nums[i % n];
        }
        
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);
        int i = 0, j = 0;
        int currOnes = 0;
        int maxCount = 0;
        
        while (j < 2 * n) {
            if (temp[j] == 1) currOnes++;
            
            if (j - i + 1 > totalOnes) {
                if (temp[i] == 1) currOnes--;
                i++;
            }
            
            maxCount = max(maxCount, currOnes);
            j++;
        }
        
        return totalOnes - maxCount;
    }
};