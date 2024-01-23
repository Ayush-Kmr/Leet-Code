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
    void helper(TreeNode* root, int &sum, int dir){
        if(!root) return ;
        
        if(!root->left && !root->right && dir==1){
            sum+=root->val;
        }
        
        helper(root->left,sum,1);
        helper(root->right,sum,2);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        helper(root,sum,0);
        
        return sum;
    }
};