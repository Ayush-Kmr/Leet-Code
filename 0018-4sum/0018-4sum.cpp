class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>ans1;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long value = target - nums[i];
                int start = j+1;
                int end = n-1;
                while(start<end){
                    if(nums[start] + nums[end]  == value- nums[j]){
                        ans1.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                    }
                    else if(nums[start] + nums[end] < value- nums[j]){
                        start++;
                    }
                    else{
                        end--;
                    }
                }
            }
        }
        vector<vector<int>>ans(ans1.begin(),ans1.end());
        return ans;
    }
};