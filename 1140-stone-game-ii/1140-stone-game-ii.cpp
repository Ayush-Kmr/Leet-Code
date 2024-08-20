class Solution {
private:
    int f(vector<int>& piles, vector<vector<vector<int>>>& dp, int p, int i, int m) {
        const int n = piles.size();
        if (i == n) {
            return 0;
        }
        if (dp[p][i][m] != -1) {
            return dp[p][i][m];
        }
        int res = p == 1 ? INT_MAX : -1;
        int s = 0;
        for (int x = 1; x <= min(2 * m, n - i); x++) {
            s += piles[i + x - 1];
            if (p == 0) {
                res = max(res, s + f(piles, dp, 1, i + x, max(m, x)));
            }
            else {
                res = min(res, f(piles, dp, 0, i + x, max(m,x)));
            }
        }
        dp[p][i][m] = res;
        return res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        vector dp(2, vector(n + 1, vector<int>(n + 1, -1)));
        return f(piles, dp, 0, 0, 1);
    }
};