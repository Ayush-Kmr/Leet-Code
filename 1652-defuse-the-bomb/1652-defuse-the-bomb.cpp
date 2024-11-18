class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>temp;
        temp.insert(temp.end(), code.begin(),code.end());
        temp.insert(temp.end(), code.begin(),code.end());
        
        vector<int>ans;
        for(int i=0; i<code.size(); i++){
            long long sum = 0;

        if (k > 0) {
            int j = i + 1;
            int count = 0;
            while (count < k && j < temp.size()) {
                sum += temp[j];
                j++;
                count++;
            }
            ans.push_back(sum);
        } else if (k == 0) {
            std::fill(code.begin(), code.end(), 0);
            return code;
        } else {
            int j = i + code.size() - 1;;
            int count = 0;
            while (count < -k && j >= 0) {
                sum += temp[j];
                j--;
                count++;
            }
            ans.push_back(sum);
        }
    }

    return ans;
    }
};