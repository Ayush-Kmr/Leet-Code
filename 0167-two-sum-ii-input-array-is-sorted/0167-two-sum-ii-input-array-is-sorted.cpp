class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int m=numbers.size();
         for(int i=0; i<m; i++){
            int f=target-numbers[i];
             int l=i+1;
             int h=m-1;
            // cout<<l<<" "<<h;
             while(l<=h)
             {
                 int mid= l+(h-l)/2;
                 if(numbers[mid]==f)
                     return {i+1,mid+1};
                 else if(numbers[mid]>f)
                     h=mid-1;
                 else l=mid+1;
             }
         }
             return { };
    }
};