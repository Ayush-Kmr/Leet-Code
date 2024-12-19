class Solution {
public:
    int maxChunksToSorted(vector<int>& a) {
        int n = a.size();
        int s = 0,cs = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            s+=i;
            cs+=a[i];
            if(s == cs)
                ans++;
        }
        return ans;
    }
};