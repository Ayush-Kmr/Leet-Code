class Solution {
public:
    int passThePillow(int n, int time) {
        int dir =1;
        int idx =1;
        while(time){
            if(idx + dir >=1 && idx +dir <=n){
                idx+=dir;
                time--;
            }
        else dir*=-1;
        }
        return idx;
    }
};