class Solution {
public:
    
    bool solve(vector<int>quantity, map<int,int>&mp, int index){
        if(index == quantity.size()){
            return true;
        }
        
        for(auto it= mp.begin(); it!= mp.end(); it++){
            if(it->second >= quantity[index]){
                mp[it->first] = mp[it->first] - quantity[index];
                bool nextsol = solve(quantity,mp, index+1);
                if(nextsol == true) return true;
                
//                 Backtrack
                mp[it->first] +=quantity[index];
            }
        }
        
        return false;
    }
    bool canDistribute(vector<int>& nums,vector<int>& quantity) {
//         Counting the frequency of the number
        map<int, int> mp;
        for (auto i : nums) mp[i]++;
        
        int m = quantity.size();
        int count = 0;
        
//         Sort an array in descending order
        sort(quantity.begin(),quantity.end(),greater<int>());
        
        bool ans = solve(quantity, mp, 0);
        
        return ans;

    }
};