class Solution {
public:
    bool go( unordered_map<int,vector<int>>&mp, int i, int d,vector<bool>&v,int c,int n)
    {
        if(i==d)return 1;
        if(v[i])return 0;
        if(c>n)return 0;
        
        v[i]=1;
        
        bool ans=0;
        
        for(auto j : mp[i])
            ans|=go(mp,j,d,v,c+1,n);
        
        return ans;
        
        
    }
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        
        unordered_map<int,vector<int>>mp;
        for(auto i: edges)
        {
            mp[i[0]].push_back(i[1]);
             mp[i[1]].push_back(i[0]);
            
        }
        vector<bool>v(n,0);
     
        return go(mp,s,d,v,0,n);
    }
};
   