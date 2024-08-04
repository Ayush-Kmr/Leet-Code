class Solution {
public:
 const int MOD = 1e9 + 7;
 void subarraysum(vector<int>& nums,vector<int>&sub) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                sub.push_back(sum);
            }
        }
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sub;
        subarraysum(nums,sub);
        sort(sub.begin(),sub.end());
        long sum =0;
        for(int i=left-1; i<=right-1; i++){
            sum += sub[i]%MOD;
        }
        return sum%MOD;
    }
};

