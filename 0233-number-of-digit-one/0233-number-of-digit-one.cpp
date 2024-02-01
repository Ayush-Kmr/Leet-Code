class Solution {
public:
    
    int solve(int n ){
        if(n<= 0) return 0;
        if(n<10) return 1;
        int length = to_string(n).size();
        int base = pow(10,length -1);
        int firstdigit = n/base;
        int rem = n% base;
        int oneinbase= 0;
        if(firstdigit == 1) oneinbase= n - base +1;
        else oneinbase = base;
        
        return solve(rem) + oneinbase + firstdigit*solve(base-1);
    }
    int countDigitOne(int n) {
        int ans = solve(n);
        return ans;
    }
};