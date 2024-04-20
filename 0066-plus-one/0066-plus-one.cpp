class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n =  digits.size() - 1;
        int carry = 0;
        for(int i=n; i>=0; i--){
            if(digits[i]<9){
                digits[i] += 1;
                return digits;
            }
            else {
                digits[i] =0;
                carry =1;
            }
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};