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
    set<int> st; 

    TreeNode* deleteHelper(TreeNode* root, vector<TreeNode*>& ans) {
        if(!root) return NULL;

        root->left = deleteHelper(root->left, ans);
        root->right = deleteHelper(root->right, ans);
        if(st.find(root->val) != st.end()){
            if(root->left!= NULL) ans.push_back(root->left);
            if(root->right!=NULL) ans.push_back(root->right);
            return NULL;
        }
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        for (auto i : to_delete) st.insert(i);

        root = deleteHelper(root, ans);

        if (root && st.find(root->val) == st.end()) ans.push_back(root);

        return ans;
    }
};
