class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return 0;
        long long x=n;
      return( x&(x-1))==0;   
    }
};