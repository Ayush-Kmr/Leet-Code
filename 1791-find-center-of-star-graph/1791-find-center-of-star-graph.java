import java.util.ArrayList;

class Solution {
    public int findCenter(int[][] edges) {
        ArrayList<Integer> nums = new ArrayList<>();
        int n = edges.length;
        int m = edges[0].length;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nums.add(edges[i][j]);
            }
        }
        Collections.sort(nums);
        if(nums.get(0)==nums.get(1)){
            return nums.get(0);
        }
        else
            return nums.get(n);
        // int high = nums.size(); // Use .size() to get the size of ArrayList
        // int low = 0;
        // int mid = low + (high - low) / 2; // Calculate mid based on nums.size()
        // if(m%2 != 0)return nums.get(n);
        // else return (nums.get(n-1));
    }
}
