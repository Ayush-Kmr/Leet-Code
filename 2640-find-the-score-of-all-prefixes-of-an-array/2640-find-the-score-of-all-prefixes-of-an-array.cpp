class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        long long prefix_sum = 0;
        long long max_prefix = INT_MIN;
        vector<long long>ans;
        for(int i=0; i<n; i++){
            max_prefix = max(max_prefix,(long long)nums[i]);
            prefix_sum += nums[i] + max_prefix;
            ans.push_back(prefix_sum);
        }
        return ans;
    }
};