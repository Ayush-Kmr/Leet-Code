class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int currsum=0;
        helper(arr,0,temp,ans,currsum,target);
            return ans;
    }
    
    
    void helper(vector<int>arr,int index,vector<int>&temp,vector<vector<int>>&ans,int currsum,int target){
        if(currsum==target){
            ans.push_back(temp);
            return ;
        }
        if(currsum>target) return ;
        for(int i=index; i<arr.size(); i++){
        if(currsum<=target){
            temp.push_back(arr[i]);
            currsum+=arr[i];
            helper(arr,i,temp,ans,currsum,target);
            currsum-=arr[i];
            temp.pop_back();
        }
      }
    }
};