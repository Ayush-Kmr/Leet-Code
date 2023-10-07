class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
            return 1;
        if(n<=0)
            return 0;
        int value=log(n)/log(4);
        return(pow(4,value)==n);
    }
};