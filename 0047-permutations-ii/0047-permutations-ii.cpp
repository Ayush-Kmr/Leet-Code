#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        helper(index, nums,ans);
        
        return ans;
    }

    void helper(int index, vector<int>& arr,vector<vector<int>>& ans) {
        map<int,int>mp;
        if (index == arr.size()) {
            ans.push_back(arr);
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            if (mp.count(arr[i]) && mp[arr[i]] > 0) continue;
            else {
                mp[arr[i]]++;
                swap(arr[index], arr[i]);
                helper(index + 1, arr,ans);
                swap(arr[index], arr[i]);
            }
        }
    }
};
