/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* node , int &min_depth, int curr_depth){
        if(!node ) return ;
        if(!node->left && !node->right) min_depth  = min(min_depth,curr_depth);
        helper(node->left,min_depth,curr_depth+1);
        helper(node->right,min_depth,curr_depth+1);
    }
    int minDepth(TreeNode* root) {
         if(root == NULL) return 0;
         int min_depth =1e6;
        helper(root,min_depth ,1);
        return min_depth;
    }
};