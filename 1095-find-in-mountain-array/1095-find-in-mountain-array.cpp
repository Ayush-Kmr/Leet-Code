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
    int search(MountainArray &nums,int t,int l,int h,bool flag)
    {  while(l<=h)
        {int m=l+(h-l)/2;
        int mid=nums.get(m);
     if(mid==t)return m;
     bool b=t>mid;
         if(b^flag)
             l=m+1;
         else h=m-1;
         }
     return -1;
    }
    int findInMountainArray(int t, MountainArray &nums) {
        int n=nums.length();
        int l=0;
        int h=n-1;
        while(l<h)
        {
            int m=l+(h-l)/2;
            int mid=nums.get(m);
            if(nums.get(m+1)>mid)
                l=m+1;
            else h=m;
            
        }
        
        int s1=search(nums,t,0,h,0);
        if(s1!=-1)return s1;
        return search(nums,t,h,n-1,1);
       
    }
};