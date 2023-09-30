class Solution {
public:
    string helper(string s)
    {
       string ans;
        
        for (auto i :s)
        {
            if(i!='#')
            {
                ans.push_back(i);
            }
            else if(!ans.empty())
            {
                ans.pop_back();
            }
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        
        return helper(s)== helper(t);
        
    }
};