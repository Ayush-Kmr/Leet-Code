class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long sum=0;
        long long y=x;
        while(y!=0){
            int temp=y%10;
            sum=sum*10+temp;
            y=y/10;
        }
        return(sum==x);
    }
};