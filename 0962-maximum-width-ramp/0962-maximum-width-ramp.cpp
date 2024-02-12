class Solution {
public:
    int maxWidthRamp(std::vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int ans = 0;

        // Monotonic decreasing stack to store indices
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }

        // Iterate from the end of the array to find the maximum width ramp
        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && nums[j] >= nums[st.top()]) {
                int i = st.top();
                ans = max(ans, j - i);
                st.pop();
            }
        }

        return ans;
    }
};