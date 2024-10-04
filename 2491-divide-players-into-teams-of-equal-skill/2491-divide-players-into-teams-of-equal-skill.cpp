class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int i = 0, j = n - 1;
        long long sum = 0;
        long long prev = skill[i] + skill[j];        
        while (i < j) {
            long long temp = skill[i] + skill[j];
            if(temp != prev) return -1;
            prev = temp;
            sum += static_cast<long long>(skill[i++]) * skill[j--]; 
        }
        return sum;
    }
};
