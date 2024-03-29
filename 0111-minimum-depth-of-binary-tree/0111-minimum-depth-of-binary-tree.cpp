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
    int minDepth(TreeNode* root) {
         if(root == NULL) return 0;
         if(!root->left && !root->right) return 1;
        int left_depth = 1e6, right_depth = 1e6;
        if(root->left) left_depth  = minDepth(root->left);
        if(root->right) right_depth = minDepth(root->right);
        
        return 1 + min(left_depth, right_depth);
    }
};