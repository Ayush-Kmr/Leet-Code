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

    bool check(TreeNode* p, TreeNode* q){
        if(!p && !q) return 1;
        if(!p && q || p && !q) return 0;
        if(p->val != q->val) return 0;

        bool op1 = check(p->left,q->left);
        bool op2= check(p->right,q->right);

        int ans = op1 && op2;

        return ans;


    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check (p,q);
    }
};