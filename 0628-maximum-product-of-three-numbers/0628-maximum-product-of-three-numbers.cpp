class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n= nums.size();
        int f_max = INT_MIN;
        int s_max = INT_MIN;
        int t_max = INT_MIN;
        int f_min = INT_MAX;
        int s_min = INT_MAX;
        for(int i =0; i<n; i++){
            
//             Three maximum value of the array
            if(nums[i]>=f_max){
                t_max = s_max;
                s_max = f_max;
                f_max = nums[i];
            }
            else if(nums[i] >=s_max && nums[i] != f_max){
                t_max = s_max;
                s_max = nums[i];
            }
            else if(nums[i]>=t_max && nums[i]!= s_max && nums[i]!=f_max) {
                t_max = nums[i];
            }
            
//             Two minimum value of the given array
            if(nums[i]<=f_min){
                s_min=f_min;
                f_min = nums[i];
            }
            else if(nums[i]<=s_min && f_min!= nums[i]){
                s_min = nums[i];
            }
        }
        
       return max( f_min*s_min*f_max, f_max*s_max*t_max);
    }
};