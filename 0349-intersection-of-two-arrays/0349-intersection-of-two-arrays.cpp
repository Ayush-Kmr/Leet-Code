class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_set<int>st;
        for(auto i:nums1) st.insert(i);
        for(int i=0; i<nums2.size(); i++){
            if(st.find(nums2[i]) != st.end()){
                ans.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
        }
        return ans;
    }
};