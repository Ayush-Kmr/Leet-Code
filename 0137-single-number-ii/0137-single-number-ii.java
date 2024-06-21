class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer,Integer> mp= new HashMap<>();
         for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        }
        for(int i=0; i<nums.length; i++){
            int num = nums[i];
            if(mp.get(num) == 1) {
                return num;
            }
        }
        return -1;
     }
}