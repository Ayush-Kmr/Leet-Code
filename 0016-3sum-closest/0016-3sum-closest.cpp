class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int  n  = nums.size();
        long long sum = nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<n; i++){
            int start =i+1;
            int end= n-1;
            while(start<end){
    long long currsum =  static_cast<long long>(nums[i]+nums[start]+nums[end]);
            if(abs(sum-target)>=abs(currsum-target)) sum =currsum;
             if(currsum>target) end--;
             else start++;
            }
        }
        return static_cast<int>(sum);
    }
};