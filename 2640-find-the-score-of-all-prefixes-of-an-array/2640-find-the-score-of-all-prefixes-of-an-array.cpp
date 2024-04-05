class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        long long prefix_sum = 0;
        long long max_prefix = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            max_prefix = max(max_prefix, (long long)nums[i]);
            prefix_sum += max_prefix + nums[i];
            ans[i] = prefix_sum;
        }

        return ans;
    }
};
