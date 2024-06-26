/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private void inOrder(TreeNode root,List<Integer>vec){
        if(root == null) return ;
        inOrder(root.left,vec);
        vec.add(root.val);
        inOrder(root.right,vec);
    }
    
    private TreeNode construct(int start, int end, List<Integer>vec){
        if(start > end) return null;
        int mid = start + (end - start)/2;
        TreeNode root = new TreeNode(vec.get(mid));
        root.left = construct(start,mid-1,vec);
        root.right = construct(mid+1,end,vec);
        return root;
    }    
    
    public TreeNode balanceBST(TreeNode root) {
        if(root == null) return null;
        List<Integer> vec = new ArrayList<>();
        inOrder(root,vec);
        return construct(0,vec.size()-1,vec);
        
    }
}