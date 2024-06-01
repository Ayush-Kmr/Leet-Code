class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size();
        int sum =0;
        for(int i=1; i<n; i++){
            int diff =0;
            int asci1 = s[i-1];
            int asci2 = s[i];
            diff = abs(asci1 - asci2);
            sum += diff;
        }
        return sum;
    }
};