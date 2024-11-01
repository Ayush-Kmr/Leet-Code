class Solution {
public:
    int n;
    unsigned max_OR;
    vector<vector<int>> dp; // (i, acc_or)
    int f(int i, unsigned acc_or, vector<int>& nums){
        if (i<0) return (acc_or==max_OR)?1:0;
        if (dp[i][acc_or]!=-1) return dp[i][acc_or];
        int skip=f(i-1, acc_or, nums);
        int take=f(i-1, acc_or| nums[i], nums);
        return dp[i][acc_or]=skip+take;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();
        max_OR=accumulate(nums.begin(), nums.end(), 0, bit_or<>());
        dp.assign(n, vector<int>(max_OR+1, -1));
        return f(n-1, 0, nums);
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();