class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {        
        unordered_map<int, int> currentWindow;
        
        int left, right;
        left = right = 0;
        
        for(; right < nums.size(); right++) {
            // start removing elements from head.
            if(right > k) {
                currentWindow[nums[left]]--; // this makes that element in map = 0, essentially.
                left++; // shrinking the window.
            }
            
            if(currentWindow[nums[right]] == 1)
                return true;    // found it earlier, nice.
            
            // didn't find the element earlier, add it to the map.
            currentWindow[nums[right]]++;
        }
        
        return false;
    }
};