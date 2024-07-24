class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> mp;

        for(int i = 0; i<n;i++){

            int temp = nums[i];
            int newNum = 0;
            int tens = 1;

            if(temp==0)
                newNum = mapping[0];

            while(temp>0){
                newNum += tens*mapping[temp%10];
                tens*=10;
                temp /= 10;
            }

            mp.push_back({newNum, i});
        }

        sort(mp.begin(), mp.end());

        vector<int> ans(n);
        for(int i=0;i<n;i++)
            ans[i] = nums[mp[i].second];
        
        return ans;
    }
};