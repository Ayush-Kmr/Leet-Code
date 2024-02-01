class MinStack {
public:
    vector<int> ans;
    MinStack() {
        
    }
    
    void push(int val) {
       ans.push_back(val);
    }
    
    void pop() {
        if(!ans.empty()) ans.pop_back();
    }
    
    int top() {
        if(!ans.empty()) return ans[ans.size()-1];
        else return -1;
    }
    
    int getMin() {
        int sol = INT_MAX;
        for(auto i:ans){
          sol  = min(i,sol);
        }
        return sol;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */