class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> > num;
        for(int i=0;i<nums.size();i++)
        {
            num.push_back({ nums[i] , i }); 
        }
        sort(num.begin(), num.end());
        
        int start=0;
        int end= num.size() -1;
        
        while(end>start)
        {
            if(num[start].first  + num[end].first == target)
            {
                return {num[start].second , num[end].second };
            }
            else if(num[start].first  + num[end].first < target)
            {
                start++;
            }
            else{
                end--;
            }
        }
        return {-1,-1};
    }
};
