class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int size=n-1;
        for(int i=n-1;i>=0;i--)
        if(nums[i]<=0)swap(nums[i],nums[size--]);
       
        for(int i=0;i<=size;i++)
        {
            int ind= abs(nums[i]);
            ind=ind-1;
            if(ind<=size && nums[ind]>0)nums[ind]*=-1;
        }
        for(int i=0;i<=size;i++)
            if(nums[i]>0)return i+1;
        
         
              
       return size+2;
    }
};