class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>mp;
        vector<vector<int>>temp;
        int n= nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            temp.push_back({i.second,i.first});
        }
         sort(temp.begin(),temp.end());
        for(int  i=temp.size()-1; k>0 && i>=0; i--,k--){
            ans.push_back(temp[i][1]);
            
        }
        return ans;
    }
};