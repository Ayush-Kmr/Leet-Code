class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        int m = arr.size();
        if(n != m) return false;
        
        unordered_map<int, int> mp; 
        
        for(auto i: arr){
            mp[i]++;
        }
        
        for(int i = 0; i < n; i++){
            int value = target[i];
            if(mp.find(value) != mp.end()){ 
                int freq = mp[value];
                if(freq == 1) mp.erase(value);
                else mp[value]--;
            } else {
                return false;
            }
        }
        return true;
    }
};
