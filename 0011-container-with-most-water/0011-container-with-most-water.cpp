class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size()-1;
        int low=0;
        int high=n;
        int maxarea=0;
        while(low<=high){
            int minheight = min(height[high],height[low]);
            int area=(high-low)*minheight;
            maxarea=max(area,maxarea);
            if(height[high]<height[low]){
                high--;
                }
            else{
                low++;
            }
        }
        return maxarea;
        
    }
};