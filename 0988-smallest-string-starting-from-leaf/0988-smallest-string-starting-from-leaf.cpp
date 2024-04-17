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
    string res ="~~";
    void solve(TreeNode* root, string curr){
        if(!root) return ;
        curr = char('a' + root->val) + curr;
        if(!root->left && !root->right){
            res = min(curr,res);
            return ;
        }
        solve(root->left,curr);
        solve(root->right,curr);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        solve(root,"");
        return res;
    }
};