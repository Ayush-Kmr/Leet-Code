import java.util.*;

public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        List<Integer> resultList = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();
        
        // Count frequencies of elements in nums1
        for (int num : nums1) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        
        // Check intersection with nums2 and decrement count in map
        for (int num : nums2) {
            if (map.containsKey(num) && map.get(num) > 0) {
                resultList.add(num);
                map.put(num, map.get(num) - 1);
            }
        }
        
        // Convert List<Integer> to int[]
        int[] resultArray = new int[resultList.size()];
        for (int i = 0; i < resultList.size(); i++) {
            resultArray[i] = resultList.get(i);
        }
        
        return resultArray;
    }
}
