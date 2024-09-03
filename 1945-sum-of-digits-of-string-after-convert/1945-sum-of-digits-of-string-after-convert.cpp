class Solution {
public:
    int getLucky(std::string s, int k) {
        std::unordered_map<char, int> letterToValue;
        for (char i = 'a'; i <= 'z'; ++i) {
            letterToValue[i] = i - 'a' + 1; 
        }
        string value;
        for (char c : s) {
            if (std::islower(c)) {
                value += to_string(letterToValue[c]);
            }
        }

        if (value.empty()) {
            return 0;
        }
        int temp = 0;
        for (char c : value) {
            temp += c - '0';
        }
        for (int i = 1; i < k; ++i) {
            int sum = 0;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            temp = sum;
        }

        return temp;
    }
};
