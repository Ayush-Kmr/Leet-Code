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
    
    void helper(TreeNode* root ,int &ans,int dir){
        
        if(!root) return ;
        if(!root->left && !root->right && dir==1 ){
            ans+=root->val;
        }
        
        helper(root->left,ans,1);
        helper(root->right,ans,0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans =0;
        
        helper(root,ans,0);
        
        
        return ans;
        
    }
};