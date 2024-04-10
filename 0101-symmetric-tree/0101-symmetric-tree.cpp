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
    bool check(TreeNode* node1 , TreeNode* node2){
        if(!node1 && !node2) return true;
        if(!node1 && node2 || node1 && !node2) return false;
        if (node1->val != node2->val)  return false; 
        bool ans1 = check(node1->left, node2->right);
        bool ans2 = check(node1->right, node2->left);
        return ans1 && ans2;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        return check(root->left, root->right);
    }
};