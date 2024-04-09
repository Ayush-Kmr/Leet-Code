class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int count =0;
        int value = tickets[k];
        for(int i=0; i<n; i++){
           if(i<=k) count +=min(tickets[i],tickets[k]);
           else if(i>k) count +=min(tickets[i],tickets[k]-1);
        }
        return count;
    }
};