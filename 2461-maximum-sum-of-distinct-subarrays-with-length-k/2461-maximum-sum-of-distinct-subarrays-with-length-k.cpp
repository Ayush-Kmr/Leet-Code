class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        std::set<int> st;
        long long sum = INT_MIN;
        long long temp = 0;

        int left = 0;
        for (int right = 0; right < n; right++) {
            while (st.find(nums[right]) != st.end()) {
                st.erase(nums[left]);
                temp -= nums[left];
                left++;
            }
            st.insert(nums[right]);
            temp += nums[right];
            if (right - left + 1 == k) {
                sum = std::max(sum, temp);
                st.erase(nums[left]);
                temp -= nums[left];
                left++;
            }
        }

        return sum == INT_MIN ? 0 : sum;
    }
};
