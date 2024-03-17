class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int value = target - nums[i];
            if(m.count(value)){return {m[value],i};}
            m[nums[i]] = i;
        }
        return { }; 
    }
};