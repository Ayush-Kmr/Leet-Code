class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0, 1); // Initialize with 0 odd count with 1 occurrence (base case)
        
        int result = 0;
        int oddCount = 0;
        
        for (int i = 0; i < nums.length; i++) {
            oddCount += nums[i] % 2;
            
            // Check if there exists a previous oddCount - k
            if (mp.containsKey(oddCount - k)) {
                result += mp.get(oddCount - k);
            }
            
            // Update the HashMap with the current oddCount
            mp.put(oddCount, mp.getOrDefault(oddCount, 0) + 1);
        }
        
        return result;
    }
}
