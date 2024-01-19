class Solution {
public:
    int solve(int n){
        if(n==1){
            return 1;
        }
        
        return 2*(1+n/2 - solve(n/2));
    }
    
    int lastRemaining(int n) {
        int x = solve(n);
        
        return x;
         
    }
};