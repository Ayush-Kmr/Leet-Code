class Solution {
public:
    int numberOfMatches(int n) {
        int sum=0;
        int matches;
        while(n>1){
            if(n%2 != 0){
                matches=(n-1)/2;
                sum+=matches;
                n=matches+1;
            }
            else{
                matches=(n)/2;
                sum+=matches;
                n=matches;
            }
        }
        return sum;
    }
};