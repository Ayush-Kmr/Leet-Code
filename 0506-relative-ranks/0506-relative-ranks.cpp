class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp(score.size());
        vector<string> ans(score.size());
        for (int i = 0; i < score.size(); i++) {
            temp[i] = score[i];
        }
        sort(temp.begin(), temp.end(), greater<int>());
        map<int, int> mp;
        for (int i = 0; i < temp.size(); i++) {
            mp[temp[i]] = i + 1;
        }
        
        for (int i = 0; i < score.size(); i++) {
            if (mp[score[i]] == 1) {
                ans[i] = "Gold Medal";
            } else if (mp[score[i]] == 2) {
                ans[i] = "Silver Medal";
            } else if (mp[score[i]] == 3) {
                ans[i] = "Bronze Medal";
            } else {
                ans[i] = to_string(mp[score[i]]);
            }
        }
        
        return ans;
    }
};
