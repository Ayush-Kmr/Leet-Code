class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = spaces.size();
        int spaceIndex  = 0;
        string ans =  "";
        for(int i=0; i<s.length(); i++){
            if(spaceIndex < n && i == spaces[spaceIndex]){
                ans += " ";
                spaceIndex++;
            }
            ans += s[i];
        }
        return ans;
    }
};