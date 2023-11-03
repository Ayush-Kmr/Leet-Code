class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right (n,0);
        right[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--){
            right[i]=max(height[i],right[i+1]);
        }
        int left=height[0];
        int ans=0;
        for(int i=1; i<n-1; i++){
            int x=min(left, right[i] )-height[i];
            if(x>0){
                ans+=x;
            }
            left=max(left,height[i]);
        }
        
        return ans;
    }
};