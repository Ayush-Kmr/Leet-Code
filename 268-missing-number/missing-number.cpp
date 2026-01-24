class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xors = 0;
        for(int i=0; i<=nums.size(); i++)xors ^= i;
        for(auto i: nums) xors^= i;
        return xors;
    }
};