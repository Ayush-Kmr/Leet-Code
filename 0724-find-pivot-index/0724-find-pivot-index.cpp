class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int n=nums.size();
        int s=0;
        for(int i: nums)s+=i;
        int l=0;
        for(int i=0;i<n;i++)
        {
           
            if(s-nums[i]==2*l)return i;
            l+=nums[i];
        }
        return -1;
    }
};