class Solution {
public:
    int arrangeCoins(int n) {
       long long int x=0;
       for(int i=1;;i++)
       {
           x+=i;
           if(x>n)
               return i-1;
       }
        return 0;
    }
};