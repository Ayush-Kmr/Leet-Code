class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        vector<int> mi(n, INT_MAX); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mi[i] = min(mi[i], matrix[i][j]);
            }
        }

        vector<int> mx(m, INT_MIN); 
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                mx[j] = max(mx[j], matrix[i][j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == mi[i] && matrix[i][j] == mx[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};
