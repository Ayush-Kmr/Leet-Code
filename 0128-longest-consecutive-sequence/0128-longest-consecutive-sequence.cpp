class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        sort(nums.begin(),nums.end());
        int count=1;
        int ans=1;
        for(int i =1 ; i<n; i++){
            if(nums[i] == (nums[i-1] + 1)) count++;
            else if(nums[i]==nums[i-1]) continue;
            else{
                ans = max(ans,count);
                count=1;
            }
        }
        return max(ans,count);
    }
};