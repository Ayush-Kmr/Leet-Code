/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
     bool findPath(TreeNode* root, TreeNode* value, vector<TreeNode*>&path){
        if(!root) return false;
        path.push_back(root);
        if(root == value) return true;
        if(findPath(root->left,value,path) || findPath(root->right,value,path))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        vector<TreeNode*>path1,path2;
        if(!findPath(root,p,path1) || !findPath(root,q,path2)) return NULL;
        TreeNode* ans = NULL;
        int i=0;
        while(i<path1.size() && i<path2.size()){
            if(path1[i] == path2[i]) ans = path1[i];
            i++;
        }
        return ans;
    }
};