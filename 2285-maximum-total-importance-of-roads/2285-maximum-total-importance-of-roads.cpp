using namespace std;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<long, long> mp;
        for(int i = 0; i <roads.size(); i++) {
            mp[roads[i][0]]++;
            mp[roads[i][1]]++;
        }
        vector<long>vec;
        for(auto& p : mp) {
            vec.push_back(p.second);
        }
        sort(vec.begin(), vec.end(), greater<long>());
        long long sum = 0;
        for(int i = 0; i < vec.size(); i++) {
            sum += (long long)vec[i] * n--;
        }
        return sum;
    }
};
