class Solution {
public:
    int squareOfDigits(int n){
        int value = 0;
        while(n>0){
            value += (n%10) * (n%10);
            n/=10;
        }
        return value;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = squareOfDigits(slow);
            fast = squareOfDigits(squareOfDigits(fast));
        }while(slow != fast);
        return slow == 1 ? true : false;
    }
};