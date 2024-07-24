class Solution {
public:
    int getNumber(int num, vector<int> &mapping) {
        if (num == 0) return mapping[0];

        int opt = 0;
        int factor = 1;

        while (num) {
            opt += mapping[num % 10] * factor;
            factor *= 10;
            num /= 10;
        }

        return opt;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int mapped_a = getNumber(a, mapping);
            int mapped_b = getNumber(b, mapping);
            if (mapped_a == mapped_b)
                return false;
            return mapped_a < mapped_b;
        });
        return nums;
    }
};