class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int left =0, right =0;
        int count =0;
        while(left<nums.size() && right<nums.size()){
            mp[nums[right]]++;
            while(mp[nums[right]]>k){
                mp[nums[left]]--;
                left++;
            }
            count = max(count,right-left+1);
            right++;
        }
        return count;
    }
};