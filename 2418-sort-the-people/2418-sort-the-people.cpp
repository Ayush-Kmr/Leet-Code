class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp;
        vector<string> ans;
        for (int i = 0; i < names.size(); i++) {
            mp.insert({heights[i], names[i]}); 
        }

         for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            ans.push_back(it->second);
        }
        return ans;
    }
};