class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int count =0;
        int s=0;
        int value = tickets[k];
        for(int i=0; i<n; i++){
            if(value>= tickets[i]) count+= tickets[i];
            else if(value< tickets[i]) count+=value;
            if(i>k && tickets[i]>=value)s++;
        }
        return count-s;
    }
};