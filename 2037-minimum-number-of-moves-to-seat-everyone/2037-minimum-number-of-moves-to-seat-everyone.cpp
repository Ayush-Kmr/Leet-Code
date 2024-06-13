class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        int m = students.size();
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        
        int i=0; int j=0;
        int ans =0;
        while(i<n && j<m){
            ans += abs(seats[i++] - students[j++]);
        }
        return ans;
    }
};