class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>result;
        for(int i=0; i<queries.size(); i++){
            int index1 = queries[i][0];
            int index2 = queries[i][1];
            int xorValue = 0;
            for (int j = index1; j <= index2; j++) {
                xorValue ^= arr[j];
            }
            result.push_back(xorValue);
        }
        return result;
    }
};