class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<string>temp;
          vector<vector<string>>ans;
        sort(strs.begin(),strs.end());
        for(int i=0;i<n;i++)
        {  string s=strs[i];
            sort(s.begin(),s.end());
            temp.push_back(s);

        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(temp[j]>temp[j+1])
                {
                    swap(temp[j],temp[j+1]);
                    swap(strs[j],strs[j+1]);
                }
            }
        }
      
       vector<string>temp2;
       temp2.push_back(strs[0]);
       for(int i=1;i<n;i++)
       {
           if(temp[i]==temp[i-1])
           {
               temp2.push_back(strs[i]);
           }
           else{
               ans.push_back(temp2);
               temp2.clear();
                temp2.push_back(strs[i]);
           }
       }
       ans.push_back(temp2);
       return ans;
      
    }
};