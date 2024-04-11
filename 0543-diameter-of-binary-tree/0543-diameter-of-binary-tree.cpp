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
    int solve(TreeNode* root, int &diameter){
        if(!root) return 0;
        int left_h = solve(root->left,diameter);
        int right_h =solve(root->right,diameter);
        diameter = max(diameter, left_h+right_h);
        return 1 + max(left_h,right_h);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        solve(root,diameter);
        return diameter;
        
    }
};