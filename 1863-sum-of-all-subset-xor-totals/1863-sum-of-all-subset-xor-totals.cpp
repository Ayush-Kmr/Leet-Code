class Solution {
public:
    
    void solve(vector<int>& nums, int index, int &sum , int &xorAns){
        if(index >= nums.size()){
            sum += xorAns;
            return;
        }
        
//         Include
        xorAns ^= nums[index];
        solve(nums, index+1, sum, xorAns);
        
//         Backtrack
        xorAns ^= nums[index];
        
//         Exclude
        solve(nums,index+1, sum, xorAns);
    }
    int subsetXORSum(vector<int>& nums) {
        int index =0;
        int sum =0;
        int xorAns = 0;
        solve(nums,index,sum, xorAns);
        
        return sum;
    }
};