class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) {
            return ans; 
        }

        int i, j;
        if (k > 0) {
            i = 1;
            j = k;
        } else {
            i = n + k; 
            j = n - 1; 
        }

        
        int windowSum = 0;
        for (int pointer = i; pointer <= j; pointer++) {
            windowSum += code[pointer % n];
        }

        
        for (int index = 0; index < n; index++) {
            ans[index] = windowSum; 
            windowSum -= code[i % n]; 
            i++;
            j++;
            windowSum += code[j % n]; 
        }

        return ans;
    }
};
