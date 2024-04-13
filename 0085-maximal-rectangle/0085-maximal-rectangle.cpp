class Solution {
public:
     vector<int> nextSmaller(vector<int>&heights){
        int n = heights.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            int value = heights[i];
            while(!st.empty() && heights[st.top()]>=value){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmaller(vector<int>&heights){
        int n = heights.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=0; i<n; i++){
            int value = heights[i];
            while(!st.empty() && heights[st.top()]>=value){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    int findMaxArea(vector<int>&height){
        vector<int>next = nextSmaller(height);
        vector<int>prev = prevSmaller(height);
        int n = height.size();
        int area = INT_MIN;
        for(int i=0; i<n; i++){
            if(next[i] == -1) next[i] = n;
            int length = height[i];
            int breadth = next[i] - prev[i] - 1;
            int newarea = length * breadth;
            area = max(area, newarea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int>height(n);
        
//         Add the first row in the height - 1D
        for(int i=0; i<n; i++){
            height[i] = (matrix[0][i] == '1') ? 1 :0;
        }
        int maxArea = findMaxArea(height);
        for(int row = 1; row<m; row++){
            for(int col =0; col<n; col++){
                if(matrix[row][col] == '0') height[col] = 0;
                else height[col]+=1;  
            }
            maxArea = max(maxArea, findMaxArea(height));
        }
        return maxArea;
    }
};