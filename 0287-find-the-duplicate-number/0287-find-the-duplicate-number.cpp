class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size()-1;
        for(int i:nums){
            if(mp[i]>0)return i;
            mp[i]++;
        }
        return -1;

    }
};