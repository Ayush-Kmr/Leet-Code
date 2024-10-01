class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k, 0);

        // Count occurrences of each remainder
        for (int &num : arr) {
            int rem = (num % k + k) % k;
            mp[rem]++;
        }

        // Check pairs of remainders
        if (mp[0] % 2 != 0) return false;  // Remainder 0 should have an even count

        // Check remainder pairs
        for (int rem = 1; rem <= k / 2; rem++) {
            if (mp[rem] != mp[k - rem]) return false;
        }

        return true;
    }
};
