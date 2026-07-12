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
    int cnt = 0;

    int inorder(TreeNode* root, int k) {
       if(!root) return -1;
       int left = inorder(root->left, k);

       if(left != -1) return left;
       cnt++;
       if(k == cnt) return root->val;
       return inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};