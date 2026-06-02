class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int toBuy = INT_MAX, maxProf = INT_MIN;
        for(auto i: prices){
            toBuy = min(i, toBuy);
            maxProf = max(maxProf, abs(i-toBuy));
        }
        return maxProf;
    }
};