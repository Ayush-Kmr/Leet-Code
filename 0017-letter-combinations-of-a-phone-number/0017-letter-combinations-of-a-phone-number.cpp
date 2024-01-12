class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string temp;
        unordered_map<char,string> mp;
        mp['2'] ="abc";
        mp['3'] ="def";
        mp['4'] ="ghi";
        mp['5'] ="jkl";
        mp['6'] ="mno";
        mp['7'] ="pqrs";
        mp['8'] ="tuv";
        mp['9'] ="wxyz";
        
        if(digits.empty()){
            return ans;
        }
        
        helper(0,digits,temp,ans,mp);
        return ans;
    }
    
    void helper(int index, string digits, string &temp, vector<string>&ans,         unordered_map<char,string>mp){
        int n=digits.size();
        if(index==n){
            ans.push_back(temp);
        }
        string key = mp[digits[index]];
        int m= key.size();
        for(int i=0; i<m; i++){
            temp.push_back(key[i]);
            helper(index+1,digits,temp,ans,mp);
            temp.pop_back();
        }
    }
};