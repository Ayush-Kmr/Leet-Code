import java.util.PriorityQueue;

class Solution {
    public int longestSubarray(int[] nums, int limit) {
        int n = nums.length;
        
        // Max-Heap
        PriorityQueue<int[]> maxPq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        
        // Min-Heap
        PriorityQueue<int[]> minPq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        
        int i = 0;
        int maxLength = 0;
        
        for (int j = 0; j < n; j++) {
            maxPq.offer(new int[]{nums[j], j});
            minPq.offer(new int[]{nums[j], j});
            
            while (maxPq.peek()[0] - minPq.peek()[0] > limit) {
                i = Math.min(maxPq.peek()[1], minPq.peek()[1]) + 1;
                
                // Remove elements from maxPq that are out of range
                while (!maxPq.isEmpty() && maxPq.peek()[1] < i) {
                    maxPq.poll();
                }
                
                // Remove elements from minPq that are out of range
                while (!minPq.isEmpty() && minPq.peek()[1] < i) {
                    minPq.poll();
                }
            }
            
            maxLength = Math.max(maxLength, j - i + 1);
        }
        
        return maxLength;
    }
}
