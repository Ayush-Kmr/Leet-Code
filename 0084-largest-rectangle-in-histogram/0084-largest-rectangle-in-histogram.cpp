class Solution {
public:
    
    vector<int> nextSmaller(vector<int>heights, int n){
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
    
    vector<int> prevSmaller(vector<int>heights, int n){
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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>next(n);
        next = nextSmaller(heights,n);
        
        vector<int>prev(n);
        prev = prevSmaller(heights,n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++){
            if(next[i] == -1) next[i] = n;
            int length = heights[i];
            int breadth = next[i] - prev[i] - 1;
            int newarea = length * breadth;
            area = max(area, newarea);
        }
        return area;
    }
};