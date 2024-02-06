class Solution {
public:
    bool isSquare(int x){
        int sqr = sqrt(x);
        return sqr*sqr == x;
    }
    void solve(vector<int>nums, int index, int &ans){
        if(index>= nums.size()) ans++;
        for(int i=index; i<nums.size(); i++){
            if(i>index && nums[index]==nums[i]) continue;
            swap(nums[i],nums[index]);
            if((index==0) || (i>0 && isSquare(nums[index]+nums[index-1]))){
                solve(nums,index+1,ans);
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        int count =0;
        sort(nums.begin(),nums.end());
        solve(nums,0, count);
        return count;
    }
};