class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        int c=0;
        int temp;
        for(int i=n; i>=0; i--){
            if( digits[i]<9){
                digits[i]=digits[i]+1;
                return digits;
            }
            else{
                digits[i]=0;
                c=1;
            }
        }
 
     digits.insert(digits.begin(),1);
 
        return digits;
    }
};