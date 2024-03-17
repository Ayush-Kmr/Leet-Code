class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int>s;
        for(auto i:nums1){
            s.insert(i);
        }
        for(int i=0; i<nums2.size(); i++){
            int key = nums2[i];
            if(s.find(key) != s.end()){
                ans.push_back(key);
                s.erase(key);
            }
        }
        
        return ans;
    }
};