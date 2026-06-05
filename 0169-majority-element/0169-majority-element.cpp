class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majElement = 0, count =0;
        for(int i=0; i<n; i++){
            if(count == 0) {
                majElement = nums[i];
                count++;
            }
            else if(majElement == nums[i])count++;
            else count--;
        }
        return majElement;
    }
};