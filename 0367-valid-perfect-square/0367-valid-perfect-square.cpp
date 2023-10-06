class Solution {
public:
    bool isPerfectSquare(int num) {
        int low=2;
        int high=num/2;
        long long mid;
        if(num==1){
            return 1;
        }
        while(low<=high){
            mid=low + (high-low)/2;
            if((mid*mid)==num)
                return true;
            if((mid*mid)<num)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};