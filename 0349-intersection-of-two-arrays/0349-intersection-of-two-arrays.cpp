class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
//         Using Map
        // unordered_map<int,int>u;
        // for(int i=0; i<nums1.size(); i++){
        //     u[nums1[i]]++;
        // }
        // for(int i=0; i<nums2.size(); i++){
        //     int key = nums2[i];
        //     if(u.find(key) != u.end()){
        //         ans.push_back(key);
        //         u.erase(key);
        //     }
        // }
        
        
//         Using Set
        unordered_set<int>s;
        for(int i=0; i<nums1.size(); i++){
            s.insert(nums1[i]);
        }
        for(int i =0; i<nums2.size(); i++){
            int key = nums2[i];
            if(s.find(key) != s.end()){
                ans.push_back(key);
                s.erase(key);
            }
        }
        return ans;
    }
};