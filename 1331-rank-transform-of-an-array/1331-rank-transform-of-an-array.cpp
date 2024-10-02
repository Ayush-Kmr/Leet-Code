class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        int i=1;
       for (auto num : temp) {
            if (mp.find(num) == mp.end())  mp[num] = i++;
        }
        for(int i=0; i<arr.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};