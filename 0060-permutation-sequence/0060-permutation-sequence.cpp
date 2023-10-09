class Solution {
public:
    int fac(int n)
    { 
        if (n<=0)return 1;
        return n* fac(n-1);
    }
string solve(int p, int n, int k, string s)
{
    if (p >= n-1 )
    {
        return s;
    }

    int f = fac(n - 1 - p);

    int q = k / f;

    swap(s[p + q], s[p]);
    sort(s.begin() + p + 1, s.end());
    return solve(p + 1, n, k % f, s);
}

    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++)
         s+=('0'+i);
      
      return  solve(0,n,k-1,s);
        
    }
};