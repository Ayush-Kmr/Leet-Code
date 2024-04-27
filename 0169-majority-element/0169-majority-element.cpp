class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int value =0;
        for(auto i:nums){
            if(count == 0) value = i;
            if(value == i){
                count++;
            }
            else {
                count--;
            }
        }
        return value;
    }
};