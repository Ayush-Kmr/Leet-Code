class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        sort(nums.begin(), nums.end()); 
        int ans = 1;
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                // Skip duplicates
                continue;
            } else if (nums[i] == nums[i - 1] + 1) {
                // Consecutive elements
                count++;
            } else {
                // Not consecutive, reset count
                ans = max(ans, count);
                count = 1;
            }
        }

        // Check the last sequence
        ans = max(ans, count);

        return ans;
    }
};
