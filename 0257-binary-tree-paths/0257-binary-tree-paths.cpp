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
    void helper(TreeNode* node, string temp, vector<string>&ans){
        if(!node) return;
        if(!node->left && !node->right){
            ans.push_back(temp+to_string(node->val));
            return ;
        }
        
        helper(node->left,temp + to_string(node->val) + "->",ans);
        helper(node->right,temp + to_string(node->val) +"->",ans);
        
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp;
        if(root == NULL) return ans;
        
        helper(root,temp,ans);
        
        return ans;
    }
};