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
    bool solve(TreeNode* root, long long  l_mini, long long r_maxi){
        if(!root) return true;
        if(root->val > l_mini && root->val < r_maxi)
            return solve(root->left, l_mini, root->val) &&
                   solve(root->right, root->val, r_maxi);

        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, -1000000000000, 100000000000);
    }
};