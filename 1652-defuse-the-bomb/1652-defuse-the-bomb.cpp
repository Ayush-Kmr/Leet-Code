class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n = code.size();
        for (int i = 0; i < code.size(); i++) {
            long long sum = 0;

            if (k > 0) {
                for (int j = i + 1, count = 0; count < k; j++, count++) {
                    sum += code[j % n]; 
                }
                ans.push_back(sum);
            } else if (k == 0) {
                std::fill(code.begin(), code.end(), 0);
                return code;
            } else {
                for (int j = i + k, count = 0; count < -k; j++, count++) {
                    sum += code[(j + n) % n]; 
                }
                ans.push_back(sum);
            }
        }

        return ans;
    }
};
