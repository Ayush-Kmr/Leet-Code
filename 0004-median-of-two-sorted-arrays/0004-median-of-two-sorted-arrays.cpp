class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp;
        for(auto i: nums1) temp.push_back(i);
        for(auto j: nums2) temp.push_back(j);

        sort(temp.begin(), temp.end());

        int n = temp.size();
        int start = 0;
        int end = n-1;
        double ans ;
        while(start <= end){
            int mid = start + (end -start)/2;
            if(n % 2 == 1) return temp[mid];
            else {
                ans = double(temp[mid] + temp[mid+1])/2;
                return ans;
            }
        }
        return 0.0;
    }
};