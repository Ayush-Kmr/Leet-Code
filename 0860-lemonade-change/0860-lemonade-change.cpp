class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int countF = 0, countT = 0;

        for(int bill : bills) {
            switch(bill) {
                case 5:
                    countF++;
                    break;
                case 10:
                    if (countF == 0) return false;
                    countF--;
                    countT++;
                    break;
                case 20:
                    if (countT > 0 && countF > 0) {
                        countT--;
                        countF--;
                    } else if (countF >= 3) {
                        countF -= 3;
                    } else {
                        return false;
                    }
                    break;
            }
        }

        return true;
    }
};
