class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxe = *max_element(nums.begin(),nums.end());
        int left =0, right =0;
        int maxeCount = 0;
        int n = nums.size();
        long long ans =0;
        while(right<n){
            if(nums[right] == maxe) maxeCount++; 
            while(maxeCount >= k){
                ans += n - right;
                
                if(nums[left] == maxe) maxeCount--;
                left++;
            }
            right++;
        }
        return ans;
    }
};