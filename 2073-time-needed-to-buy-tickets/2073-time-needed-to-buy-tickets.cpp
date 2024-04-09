class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int count =0;
        while(tickets[k]!=0){
            for(int i=0; i<n; i++){
                int value = tickets[i];
                if(value>0 && tickets[k]!=0){
                    value--;
                    tickets[i] = value;
                    count++;
                }
            }
        }
        return count;
    }
};