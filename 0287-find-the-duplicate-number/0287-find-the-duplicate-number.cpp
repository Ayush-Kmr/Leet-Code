class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int &i:nums){
            int index=abs(i);
            if(nums[index]<0) return index;
            nums[index]*=-1;
        }
        return -1;
    }
};