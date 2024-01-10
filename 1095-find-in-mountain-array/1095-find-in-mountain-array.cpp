/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
//     =================================================
    int findPeakElement(MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0;
        int high=n-1;
        while(low<high){
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    };
    
      // ======================================================= //
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak1 = findPeakElement(mountainArr);
        int peak=peak1;
        int low =0;
        while(low<=peak){
            int mid = low + (peak-low)/2;
             int mide=mountainArr.get(mid);
            if(mide==target){
                return mid;
                
            }
            else if(mide<target){
                low=mid+1;
            }
            else{
                peak=mid-1;
            }
        }
        
//         ==========================================================   
        int high =mountainArr.length()-1;
         while(peak<=high){
            int mid = peak + (high-peak)/2;
             int mide=mountainArr.get(mid);
            if(mide==target){
                return mid;
              
            }
            else if(mide<target){
                high=mid-1;
            }
            else{
                peak=mid+1;
            }
        }
//         ===============================================================
       
        return -1;
    }
    
};