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
    void solve(TreeNode* root, map<int,vector<int>>&mp, int level){
        if(!root) return ;
        mp[level].push_back(root->val);
        solve(root->left,mp,level+1);
        solve(root->right,mp,level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        map<int,vector<int>>mp;
        vector<vector<int>>ans;
        solve(root,mp,1);
        for(auto i:mp){
            if(i.first % 2 ==0 ) reverse(i.second.begin(),i.second.end());
            ans.push_back(i.second);
        }
        return ans;
    }
};