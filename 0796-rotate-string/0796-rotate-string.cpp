class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if both strings are of the same length
        if (s.size() != goal.size()) {
            return false; // If not, they can't be rotations of each other
        }
        
        // Check if 'goal' can be found in 's' repeated twice
        return (s + s).find(goal) != string::npos;
    }
};
