class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size() - 1;
        int c=0;
        for(int i=n; i>=0 && k>=0; i--){
            num[i]=num[i]+k;
            k=num[i]/10;
            num[i]=num[i]%10;
        }
        while(k>0){
            c=k%10;
            num.insert(num.begin(),c);
            k=k/10;
        }
        return num;
    }
};