class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majElement1 = INT_MIN, majElement2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(int i=0; i<n; i++){
            if(majElement1 == nums[i]) count1++;
            else if(majElement2 == nums[i]) count2++;
            else if(count1 == 0){
                majElement1 = nums[i];
                count1++;
            }
            else if(count2 == 0){
                majElement2 = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int>ans;
        int freq1 = 0, freq2 = 0;
        for(auto i:nums){
            if(majElement1 == i) freq1++;
            else if(majElement2 == i) freq2++;
        }
        if(floor(n/3) < freq1)ans.push_back(majElement1);
        if(floor(n/3) < freq2)ans.push_back(majElement2);

        return ans;
    }
};