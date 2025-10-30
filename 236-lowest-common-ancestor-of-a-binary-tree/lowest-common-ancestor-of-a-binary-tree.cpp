/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root == p || root == q)return root;
        TreeNode* leftAnscetor = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAnscetor = lowestCommonAncestor(root->right, p, q);
        
        if(leftAnscetor && rightAnscetor) return root;
        else if (!leftAnscetor && rightAnscetor) return rightAnscetor;
        else return leftAnscetor;
    }
};