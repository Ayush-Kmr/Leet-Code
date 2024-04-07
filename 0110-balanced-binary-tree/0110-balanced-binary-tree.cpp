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
    
    int height(TreeNode* root){
        if(root == NULL) return 0;
        else return 1+ max(height(root->left),height(root->right));
    }
    
    void inorder_helper(TreeNode* root, bool&ans){
        if(root){
        inorder_helper(root->left,ans);
        int left_height = height(root->left);
        int right_height = height(root->right);
        int diff = abs(left_height - right_height);
        if(diff >1) ans = ans && false;
        inorder_helper(root->right,ans);
        }    
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        inorder_helper(root, ans);
        return ans;
    }
};