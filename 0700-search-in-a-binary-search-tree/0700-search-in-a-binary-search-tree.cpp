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
    TreeNode* searchBST(TreeNode* root, int target) {
     if(root == NULL) return NULL;
        
//         Iterative
     TreeNode* curr = root;
        while(curr){
            if(curr->val == target) return curr;
            else if(target > curr->val) curr = curr->right;
            else curr = curr->left;
        }
        return NULL;
        
        
//          Recursive
//         if(root->val == val) return root;
//      if(root->val < val) return searchBST(root->right,val);
//      else return searchBST(root->left,val);
    }
};