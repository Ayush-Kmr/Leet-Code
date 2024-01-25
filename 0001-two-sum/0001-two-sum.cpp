class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>ans;
        int n= nums.size();
        for(int i =0; i<n; i++){
            ans.push_back({nums[i],i});
        }
        
        sort(ans.begin(),ans.end());
        int start = 0;
        int end = n-1;
        
        while(start<end){
            if(ans[start].first + ans[end].first == target) return{ans[start].second,ans[end].second};
            else if(ans[start].first + ans[end].first < target) start++;
            else end--;
            
        }
        return {-1,-1};
    }
};