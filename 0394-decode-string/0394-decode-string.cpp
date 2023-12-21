class Solution {
public:

    string decodeString(string s) {
        stack<int> counts;
        stack<string> substrings;
        string result="";
        int number=0;
        string stringnumber="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>=97 and s[i]<=122)
            {
                result+=s[i];
            }
            else if(s[i]=='[')
            {
                substrings.push(result);
                result="";
                counts.push(stoi(stringnumber));
                stringnumber="";

            }
            else if(s[i]>=48 && s[i]<=57)
            {
              stringnumber+=s[i];
            }
            else
            {
                string a = substrings.top();
                substrings.pop();
                number=counts.top();
                counts.pop();
                for(int i=0;i<number;i++)
                {
                    a+=result;

                                    
                }
                result=a;

                
            }
        }
        return result;
        
    }
};