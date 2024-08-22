class Solution {
public:
    int findComplement(int num) {
        int x = num;
        vector<int> binary;
        int i = 0;
        int ans = 0;
        
        // Convert the number to binary and store it in the vector
        while (x) {
            binary.push_back(x % 2);
            x = x / 2;
            i++;
        }

        // Complement the binary bits
        for (int j = 0; j < i; j++) {
            if (binary[j] == 0) binary[j] = 1;
            else binary[j] = 0;
        }

        // Convert the binary vector back to a decimal number
        for (int j = 0; j < i; j++) {
            if (binary[j] == 1) {
                ans += pow(2, j);
            }
        }

        return ans;
    }
};
