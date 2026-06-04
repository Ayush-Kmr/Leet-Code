class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int duplicate = -1, missing = -1, count =0;
        for(int i=1; i<=n; i++){
            count = 0;
            for(int j=0; j<n; j++){
                if(i == nums[j]) count++;
        }
            if(count == 2) duplicate = i;
            else if(count == 0) missing = i;
        }
        return {duplicate, missing};
    }
};