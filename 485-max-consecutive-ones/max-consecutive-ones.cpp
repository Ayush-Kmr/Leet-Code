class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int ans = INT_MIN, oneCount =0;
        while(i<n){
             while (i < n && nums[i] == 1){
                i++;
                oneCount++;
            }
            ans = max(ans, oneCount);
            i++;
            oneCount =0;
        }
        return ans;
    }
};