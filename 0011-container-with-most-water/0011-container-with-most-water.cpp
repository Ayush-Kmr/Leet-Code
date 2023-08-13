class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size()-1;
        int low=0;
        int high=n;
        int max_area=0;
        while(low<=high){
            int min_value =min(height[low],height[high]);
            int area = (high-low)*min_value;
            max_area=max(max_area,area);
            if(height[high]<height[low]){
                high--;
            }
            else{
                low++;
            }
        }
        return max_area;
    }
};