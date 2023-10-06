class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(n<=0)return 0;
        int x=log2(n);
        return pow(2,x)==n;
    }
};