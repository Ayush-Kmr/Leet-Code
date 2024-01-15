class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
            long long curr_sum = static_cast<long long>(nums[i]) + nums[j] + nums[k];
                if (abs(ans - target) > abs(curr_sum - target)) {
                    ans = curr_sum;
                }
                if (curr_sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return static_cast<int>(ans);
    }
};
