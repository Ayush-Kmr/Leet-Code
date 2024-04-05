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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p && q || p && !q) return false;
        // if(p->val != q->val) return false;
        // bool ans1 = isSameTree(p->left, q->left);
        // bool ans2 = isSameTree(p->right, q->right);
        // return ans1 && ans2;
        return (p->val == q->val && 
                isSameTree(p->left,q->left) && 
                isSameTree(p->right,q->right));
    }
};