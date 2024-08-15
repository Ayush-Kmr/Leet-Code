class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int countF =0;
        int countT =0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5)countF++;
            else if(bills[i] == 10){
                countT++;
                if(countF) countF--;
                else return false;
            }
            else if(bills[i] == 20){
                if(countT && countF){
                    countT--;
                    countF--;
                }
                else if(countT && !countF) return false;     
                else if(countF >=3) countF -= 3;
                else if(!countT || !countF) return false;
            }
        }
        return true;
    }
};