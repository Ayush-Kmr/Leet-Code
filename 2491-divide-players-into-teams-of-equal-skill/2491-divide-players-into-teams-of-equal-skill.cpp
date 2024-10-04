class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        if (n % 2 != 0) return -1;
        
        long long sum = 0;
        long long prev =0;
        int i = 0, j = n - 1;
        
        while (i < j) {
            long long temp = skill[i] + skill[j];
            if(temp != prev && prev!=0) return -1;
            prev = temp;
            sum += static_cast<long long>(skill[i]) * skill[j]; 
            i++;
            j--;
        }
        
        return sum;
    }
};
