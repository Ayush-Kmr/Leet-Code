class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int start = i + 1;
            int end = n - 1;
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            while(start < end) {
                if(nums[start] + nums[end] == -nums[i]) {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    while(start < end && nums[start] == nums[start + 1]) start++;
                    while(start < end && nums[end] == nums[end - 1]) end--;
                    start++;
                    end--;
                }
                else if(nums[start] + nums[end] < (-nums[i])) start++;
                else end--;
            }
        }
        return ans;
    }
};
