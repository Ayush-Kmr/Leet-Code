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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        
        //         Recursive 
        // if(root->val > val) root->left=insertIntoBST(root->left,val);
        // else root->right = insertIntoBST(root->right, val);
        // return root;
        

        // Iterative
        TreeNode* curr = root;
        TreeNode* par = NULL;
        while (curr != NULL) {
            par = curr;
            if (val > curr->val) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        TreeNode* node = new TreeNode(val);
        if (val > par->val) {
            par->right = node;
        } else {
            par->left = node;
        }

        return root;
    }
};
