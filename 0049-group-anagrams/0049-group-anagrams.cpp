class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>temp;
        for(int i=0; i<strs.size(); i++){
            string str=strs[i];
            sort(str.begin(),str.end());
            temp[str].push_back(strs[i]);
        }
        
        vector<vector<string>>ans;        
        for(auto i:temp){
            ans.push_back(i.second);
        }
        return ans;
      
    }
};