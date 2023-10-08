class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index=0;
      
        for(int i=n-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                index=i-1;
                break;}
        }
        
        for(int j=n-1; j>0; j--){
            if(nums[index]<nums[j])
           { swap(nums[index],nums[j]);
             reverse(nums.begin()+index+1,nums.end());
                return;}
          
            
        }
          reverse(nums.begin(),nums.end());
    }
};