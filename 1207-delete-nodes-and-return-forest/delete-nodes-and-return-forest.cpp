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
    queue<TreeNode*> q;

    bool match(vector<int>& to_delete, int value){
        for(auto i: to_delete){
            if(i==value) return true;
        }
        return false;
    }

public:
    void solve(TreeNode* root, vector<int>& to_delete,TreeNode* prev){
        if(root==NULL){
            return;
        }
        if(match(to_delete,root->val)){
            if(root->left) q.push(root->left);  
            if(root->right) q.push(root->right);  
            if(prev){
            if(prev->left == root) prev->left = NULL;
            else prev->right = NULL;
            }
        }
        else{
            solve(root->left, to_delete, root);
            solve(root->right, to_delete, root);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return {};
        vector<TreeNode*>ans;
        q.push(root);
        while(!q.empty()){
            TreeNode* value = q.front();
            q.pop();
            if(!match(to_delete, value->val)){
            ans.push_back(value);
            }
            solve(value,to_delete,NULL);
        }
        return ans;
    }
};