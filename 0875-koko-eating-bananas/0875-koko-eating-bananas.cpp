class Solution {
public:
    bool check(vector<int>& piles,int m,int h)
    {
        int ans=0;
        for(int i:piles)
            ans+=ceil((1.0*i)/m);
        
        return ans<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1;
        int high = INT_MIN;
        for(int i:piles)high=max(high,i);

        while(start<high)
        {
            int m=start+(high-start)/2;
            if(check(piles,m,h))
                high=m;
            else start=m+1;
        }
        return start;
    }
};
