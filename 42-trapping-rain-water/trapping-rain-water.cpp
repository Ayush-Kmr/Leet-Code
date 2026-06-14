class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int>left(n,0);
        vector<int>right(n,0);
        left[0]    = height[0];
        right[n-1] = height[n-1];

        // Left -> Right
        for(int i=1; i<n; i++) left[i] = max(height[i], left[i-1]);

        // Right -> Left
        for(int i=n-2; i>=0; i--) right[i] = max(height[i], right[i+1]);

        for(int i=n-1; i>=0; i--) ans +=  min(left[i], right[i]) - height[i];
        
        return ans;
    }
};