class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans;
        for(int i=0; i<prices.size()-1; i++){
            int j = i+1;
            int value = prices[i];
            int temp = INT_MAX;
            while(j<prices.size()){
                if(value>=prices[j]) {
                    temp = prices[j];
                    break;
                }
                j++;
            }
            if(temp != INT_MAX){
                value = value - temp;
                ans.push_back(value);
            }
            else{
                ans.push_back(prices[i]);
            }
        }
        ans.push_back(prices[prices.size()-1]);
        return ans;
    }
};