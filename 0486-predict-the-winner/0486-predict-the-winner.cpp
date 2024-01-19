class Solution {
public:
    
    int solve(vector<int> & nums , int i , int j){
        if(i>j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }
        int option1= nums[i] + min(solve(nums,i+2,j),solve(nums, i+1,j-1));
        int option2= nums[j] + min(solve(nums,i,j-2),solve(nums,i+1,j-1));
        
        return max(option1, option2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=n-1;
        int p1_score = solve(nums,i,j);
        int totalScore  = 0;
        for(int i=0; i<n; i++){
            totalScore+=nums[i];
        }
        int p2_score= totalScore - p1_score;
        
        if(p1_score>=p2_score){
            return true;
        }
        return false;
    }
};