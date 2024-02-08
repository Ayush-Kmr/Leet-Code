class Solution {
public:
    int minSwaps(string s) {
        int open=0;
        int count =0;
        for(auto i:s){
            if(i=='[') open++;
            else open--;
            count = min(count,open);
        }
        return (abs(count)+1)/2;
    }
};
