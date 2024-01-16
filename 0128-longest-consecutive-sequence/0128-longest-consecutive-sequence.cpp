class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        unordered_set<int> mp(a.begin(), a.end()); // Using unordered_set for faster lookups
        int ans = 0;

        for (int num : a) {
            if (!mp.count(num - 1)) {  // Check if the current element is the start of a sequence
                int currentNum = num;
                int currentStreak = 1;

                // Count the consecutive elements starting from the currentNum
                while (mp.count(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }

                ans = max(ans, currentStreak);
            }
        }

        return ans;
    }
};
