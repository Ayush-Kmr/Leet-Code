class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size() - 1; 
        vector<int> ans;
        vector<int> res;
        int carry = 0;

        while (k > 0) {
            int value = k % 10;
            ans.push_back(value);
            k = k / 10;
        }

        int m = ans.size() - 1;
while (m != n) {
    if (m < n) {
        ans.push_back(0);
        m++;
    } else {
        num.insert(num.begin(), 0);
        n++;
    }
}

        reverse(ans.begin(), ans.end());

        for (int i = n; i >= 0; i--) {
            int sum = num[i] + ans[i] + carry;
            res.push_back(sum % 10);
            carry = sum / 10;
        }

        while (carry > 0) {
            res.push_back(carry % 10);
            carry /= 10;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};