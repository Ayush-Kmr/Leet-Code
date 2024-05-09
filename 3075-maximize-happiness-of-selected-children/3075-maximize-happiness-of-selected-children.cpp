class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long sum = 0;
        sort(h.begin(), h.end(), greater<int>());
        int i = 1;
        k--;
        sum += h[0];
        while (i < h.size() && k > 0) {
            if ((h[i] - i) > 0) {
                sum += h[i] - i;
                k--;
            }
            i++; 
        }
        return sum;
    }
};
