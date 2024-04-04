class Solution {
public:
    int maxDepth(string s) {
        int depth =0;
        int maxdepth =0;
        for(char i:s){
            if(i == '('){
                depth++;
                maxdepth = max(depth, maxdepth);
            }
            else if(i == ')') depth--;
        }
        return maxdepth;
    }
};