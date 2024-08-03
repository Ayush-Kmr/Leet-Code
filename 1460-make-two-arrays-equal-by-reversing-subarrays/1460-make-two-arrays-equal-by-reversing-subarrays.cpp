class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        int m = arr.size();
        if(n!=m) return false;
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        int i=0, j=0;
        while(i<n && j<m){
            if(target[i++] != arr[j++]) return false;
        }
        return true;
    }
};