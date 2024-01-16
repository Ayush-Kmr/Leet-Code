class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1; j<n; j++){
                long long value = target - nums[i];
                int start = j+1;
                int end = n-1;
                 if(j>i+1 && nums[j]==nums[j-1])continue;
                while(start<end){
                    if(nums[start] + nums[end]  == value - nums[j]){
                        ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                        while(start<end && nums[start]==nums[start-1]) start++;
                        while(start<end && nums[end]==nums[end+1]) end--;
                    }
                    else if(nums[start] + nums[end] < value - nums[j]){
                        start++;
                    }
                    else{
                        end--;
                    }
                }
            }
        }
        
        return ans;
    }
};