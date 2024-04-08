class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int one_count =0, zero_count =0;
        for(auto i:students){
            if(i==1) one_count++;
            else zero_count++;
        }
        for(int i=0; i<sandwiches.size(); i++){
            int sand = sandwiches[i];
            if(sand == 1){
                if(one_count == 0) return n-i;
                one_count--;
            }
            else if(sand == 0){
                if(zero_count == 0) return n-i;
                zero_count--;
            }
        }
        return 0;
    }
};