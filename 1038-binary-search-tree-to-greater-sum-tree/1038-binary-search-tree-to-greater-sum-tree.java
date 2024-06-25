class Solution {
    int sum = 0;

    public TreeNode bstToGst(TreeNode root) {
        if (root == null) return null;
        
        bstToGst(root.right); // Traverse right subtree first
        
        // Update the current node's value with the cumulative sum
        sum += root.val;
        root.val = sum;
        
        bstToGst(root.left); // Traverse left subtree
        
        return root;
    }
}