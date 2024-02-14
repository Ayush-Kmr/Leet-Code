class Solution {
public:
    
    vector<int> nextSmallerElement(vector<int>arr, int n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            while(st.top()!= -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
     
    vector<int> prevSmallerElement(vector<int>arr, int n){
        stack<int>st;
        st.push(-1);
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            int curr = arr[i];
            while(st.top()!= -1 && arr[st.top()] >= curr){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& a) {
       int n = a.size();
        vector<int> next(n);
        next = nextSmallerElement(a, n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(a, n);
        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int l = a[i];
            if(next[i] == -1) next[i] = n;
            int b = next[i] - prev[i] -1;
            int newArea = l*b;
            area = max(area,newArea);
        }
        
        return area;
    }
};