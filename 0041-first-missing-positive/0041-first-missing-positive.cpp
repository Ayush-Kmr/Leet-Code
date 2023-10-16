class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int size=n-1;
        for(int i=n-1; i>=0; i--){
            if(nums[i]<=0) swap(nums[i],nums[size--]);
        }
        for(int i=0; i<=size; i++){
            int index=abs(nums[i]);
            index=index-1;
            if(index<=size && nums[index]>0) nums[index]*=-1;
        }
        for(int i=0; i<=size; i++){
            if(nums[i]>0) return i+1;
        }
        return size+2;
    }
};