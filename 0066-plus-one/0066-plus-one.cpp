class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        int c=0;
        int temp;
        for(int i=n; i>=0; i--){
            if( digits[i]<9){
                digits[i]=digits[i]+1;
                c=0;
                break;
            }
            else{
                digits[i]=0;
                c=1;
            }
        }
 if(c)
     digits.insert(digits.begin(),1);
        
        return digits;
    }
};