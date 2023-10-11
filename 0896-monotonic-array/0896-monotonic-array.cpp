class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size()-1;
        bool flag = nums[0]<nums[n];
        
            for(int i=1; i<nums.size(); i++)
              {  if(nums[i]==nums[i-1])continue;
                if(flag != (nums[i-1]<nums[i]))
                    return 0;}
        return 1;
        
    }
};