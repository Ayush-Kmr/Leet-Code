class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector <int>v(n,0);
        int l=0;
        int r=1;
        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                v[l]=nums[i];
                l=l+2;
            }
            else{
                v[r]=nums[i];
                r=r+2;
            }
        }
        return v;
    }
};