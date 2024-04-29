class Solution {
public:
    void merge(vector<int>& nums,int start, int mid, int end){
        int idx1 = start, idx2 = mid+1;
        int i=0;
        vector<int>temp(end-start+1);
        while(idx1 <= mid && idx2 <= end){
            if(nums[idx1]< nums[idx2]){
                temp[i++] = nums[idx1++];
            }
            else{
                temp[i++] = nums[idx2++];
            }
        }
        while(idx1<= mid) temp[i++] = nums[idx1++];
        while(idx2<= end) temp[i++] = nums[idx2++];
        
        for (int k = 0; k < i; k++) {
            nums[start + k] = temp[k];
        }    
    }
    void mergeSort(vector<int>& nums,int start, int end){
        if(start < end){
        int mid = start + (end - start)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int start =0;
        int end = nums.size() -1;
        mergeSort(nums,start,end);
        return nums;
    }
};