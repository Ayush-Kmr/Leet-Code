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
    int helper(TreeNode* node, int &ans){
        if(!node) return 0;
        
        int left_sum = max(helper(node->left,ans),0);
        int right_sum = max(helper(node->right,ans),0);
        
        ans  = max(ans, left_sum + right_sum + node->val);
        
        return node->val + max(left_sum,right_sum);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};