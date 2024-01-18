class Solution {
public:
bool isValid(string s) {
        stack<char> temp;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'c') {
                if (temp.size() < 2) return false;
                
                char top1 = temp.top();
                temp.pop();
                char top2 = temp.top();
                temp.pop();
                
                if (top2 == 'a' && top1 == 'b') continue;
                else return false;
            } else {
                temp.push(s[i]);
            }
        }

        return temp.empty();
    }
};