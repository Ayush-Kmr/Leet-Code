class Solution {
public:
    int numberOfMatches(int n) {
        int sum=0;
        int value;
        while(n>1){
            if(n%2 != 0){
                value=(n-1)/2;
                sum+=value;
                n=value+1;
            }
            else{
                value=(n)/2;
                sum+=value;
                n=value;
            }
        }
        return sum;
    }
};