class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for(char i: s)
        {
           if(i=='(' || i=='{' || i=='[') 
               ans.push(i);
            else{
                if(ans.empty())return 0;
               if( i==')'  && ans.top()!='(')return false;
               if( i=='}'  && ans.top()!='{')return false;
                if( i==']'  && ans.top()!='[')return false;
                ans.pop();
            }
            
        }
    //    for(char i: ans)cout<<i<<" ";
        return ans.empty()==true;
    }
};