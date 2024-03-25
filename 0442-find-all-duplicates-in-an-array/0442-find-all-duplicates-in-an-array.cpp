class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        nums.clear();
        for(auto it=mp.begin(); it!=mp.end(); it++){
            int value = it->first;
            int freq = it->second;
            if(freq>1){
                nums.push_back(value);
            }
        }
        return nums;
    }
};