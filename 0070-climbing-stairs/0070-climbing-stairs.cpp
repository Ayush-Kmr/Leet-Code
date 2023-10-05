class Solution {
public:
    int climbStairs(int n) {
        int x=1;
        int y=1;
       int nextstep;
        if(n==1){
            return 1;
        }
        for(int i=1; i<n; i++){
           nextstep = x+y;
            x=y;
            y=nextstep;
        }
        return nextstep;
    }
};