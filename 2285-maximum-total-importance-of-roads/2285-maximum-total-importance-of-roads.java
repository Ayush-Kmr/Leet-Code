import java.util.*;

class Solution {
    public long maximumImportance(int n, int[][] roads) {
        HashMap<Integer, Integer> mp = new HashMap<>();        
        for (int i = 0; i < roads.length; i++) {
            int e1 = roads[i][0];
            int e2 = roads[i][1];
            mp.put(e1, mp.getOrDefault(e1, 0) + 1);
            mp.put(e2, mp.getOrDefault(e2, 0) + 1);
        }
        
        ArrayList<Integer> nums = new ArrayList<>(mp.values());
        Collections.sort(nums, Collections.reverseOrder());
        
        long sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += (long)nums.get(i) * n--;
        }
        
        return sum;
    }
}
