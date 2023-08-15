class Solution {
public:
    int mySqrt(int x) {
        int low=1;
        int high=x;
        long long int mid;
        if(x==0){
            return 0;
        }
        else if(x==1){
            return 1;
        }
        while(low<=high){
            mid=low+(high-low)/2;
            if((mid*mid)==x){
                return mid;
            }
            else if((mid*mid)>x){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return high;
    }
};