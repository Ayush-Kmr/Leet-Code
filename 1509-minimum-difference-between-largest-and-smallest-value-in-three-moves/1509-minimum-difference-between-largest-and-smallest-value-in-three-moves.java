class Solution {
    public int minDifference(int[] nums) {
        int n = nums.length;
        if (n <= 4) return 0;

        // Sort the array
        Arrays.sort(nums);

        // Initialize result to a large value
        int result = Integer.MAX_VALUE;

        // Compare differences of the largest and smallest elements among any four elements
        result = Math.min(result, nums[n-4] - nums[0]);
        result = Math.min(result, nums[n-3] - nums[1]);
        result = Math.min(result, nums[n-2] - nums[2]);
        result = Math.min(result, nums[n-1] - nums[3]);

        return result;
    }
}