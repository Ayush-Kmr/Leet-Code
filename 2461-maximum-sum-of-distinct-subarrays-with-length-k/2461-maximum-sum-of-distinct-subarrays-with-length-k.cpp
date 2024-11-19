class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size();
        long long left = 0, right = 0;
        set<long long>st;
        long long ans = INT_MIN, sum =0;
        
        for(; right<n; right++){
            
            while(st.find(nums[right]) != st.end()){
                sum -= nums[left];
                st.erase(nums[left]);
                left++;
            }
            
                sum += nums[right];
                st.insert(nums[right]);
            
            if((right - left) + 1  == k){
                ans = max(sum, ans);
                sum -= nums[left];
                st.erase(nums[left]);
                left++;
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};