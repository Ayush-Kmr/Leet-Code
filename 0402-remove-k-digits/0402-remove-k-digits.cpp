class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        int n = num.length();
        for(int i=0; i<n; i++){
            while(result.length()>0 && result.back()>num[i] && k>0){
                result.pop_back();
                k--;
            }
            if(result.empty() && num[i]=='0') continue;
            result.push_back(num[i]);
        }
        while(k>0 && !result.empty()){
            result.pop_back();
            k--;
        }
        if(result.empty()) return "0";
        
        return result;
    }
};