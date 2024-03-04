class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>u;
        for(int i=0; i<nums1.size(); i++){
            u[nums1[i]]++;
        }
        for(int i=0; i<nums2.size(); i++){
            int key = nums2[i];
            if(u.find(key) != u.end()){
                ans.push_back(key);
                u.erase(key);
            }
        }
        return ans;
    }
};