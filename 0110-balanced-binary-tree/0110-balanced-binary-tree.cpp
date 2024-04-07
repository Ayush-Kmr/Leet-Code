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
    int helper(TreeNode* root, bool &balanced){
        if(!root) return 0;
        int left_height = helper(root->left, balanced);
        int right_height = helper(root->right, balanced);
        if(abs(left_height - right_height)>1) balanced = false;
        
        return 1 + max(left_height, right_height);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool balanced = true;
        helper(root, balanced);
        return balanced;
    }
};