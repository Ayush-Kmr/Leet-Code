class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int ans = 0, curr = 0;
        for(auto num:st){
            if(st.find(num - 1) == st.end()){
                curr = num;
                int len = 1;

                while(st.find(curr + 1) != st.end()){
                    curr++;
                    len++;
                }
                 ans = max(ans, len);
            }
        }
        return ans;
    }
};
