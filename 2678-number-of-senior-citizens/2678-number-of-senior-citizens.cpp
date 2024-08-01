class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int count =0;
        for(int i=0; i<n; i++){
            string x = details[i];
            int s = x.size();
            string temp;
            for(int j=s-4; j<s-2; j++){
                 temp += x[j];
            }
            int value = stoi(temp);
            if(value > 60) count++;
        }
        return count;
    }
};