class Solution {
public:
    int trap(vector<int>& height) {
        int n  = height.size();
        vector<int>rm(n);
        int ans=0;
        rm[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            rm [i] = max(height[i],rm[i+1]);
        }
        int lm = height[0];
         for(int i=1; i<n; i++){
             lm = max(lm,height[i]);
             int x = min(lm,rm[i]) - height[i];
             ans+=x;
             
         }                   
        return ans;
    }
};