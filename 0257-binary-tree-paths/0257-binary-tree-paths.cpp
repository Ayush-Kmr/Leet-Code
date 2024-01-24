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
    void helper(TreeNode* root, vector<string>& ans, string s){
        if(!root) return ;
        if(s.empty())
            s+=to_string(root->val);
        else{
            s=s+"->"+to_string(root->val);
        }
        if(!root->left && !root->right) ans.push_back(s);
        
        helper(root->left,ans,s);
        helper(root->right,ans,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s;
        helper(root, ans, s);
        
        return ans;
    }
};