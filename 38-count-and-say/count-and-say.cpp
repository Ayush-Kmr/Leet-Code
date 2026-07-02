class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        for(int i=2; i<=n; i++){
            string next = "";
            int j = 0;
            while(j<curr.length()){
                char ch = curr[j];
                int count = 0;
                while(j<curr.length() && curr[j] == ch){
                    count++;
                    j++;
                }
                next += to_string(count);
                next += ch;
            }
            curr = next;
        }
        return curr;
    }
};