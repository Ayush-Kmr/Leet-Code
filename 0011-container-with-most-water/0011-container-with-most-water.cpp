class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int start = 0;
        int end = n-1;
        int max_area = 0;
        while(start<end){
            int min_value = min(height[start],height[end]);
            int area = (end - start)* min_value;
            max_area = max(area,max_area);
            if(height[start]<height[end]) start++;
            else end--;
        }
        return max_area;
    }
};