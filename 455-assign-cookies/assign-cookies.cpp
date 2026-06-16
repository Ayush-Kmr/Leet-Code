class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int n = g.size();
        int m = s.size();

        int i=0, j=0;
        int ans = 0;
       
        for(int i=0; i<n; i++){
            int greed = g[i];
            while(j<m){
                if(greed <= s[j]){
                    ans++;
                    j++;
                    break;
                }
                j++;
                if(j == m) return ans;
            }
        }
        return ans;
    }
};