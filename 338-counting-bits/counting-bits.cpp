class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        ans.push_back(0);
        for(int i=1; i<=n; i++){
            int setBitCount = 0;
            int temp = i;            
            while (temp != 0) {
                if (temp & 1) setBitCount++;
                temp >>= 1;
            }
            ans.push_back(setBitCount);
        }
        return ans;
    }
};