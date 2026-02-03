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
    pair<int,int> solve(TreeNode* root, int&ans){
        if(!root) return {0,0};
        pair<int,int>left  = solve(root->left, ans);
        pair<int,int>right = solve(root->right, ans);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if(sum / count == root->val) ans++;
        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;

        int ans = 0;

        solve(root, ans);
        return ans;
    }
};