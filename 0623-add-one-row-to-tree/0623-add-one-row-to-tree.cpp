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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return NULL;
        if(depth == 1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                
                if(depth == 2){
                    TreeNode* leftNode = new TreeNode(val);
                    leftNode->left = temp->left;
                    temp->left = leftNode;
                    
                    TreeNode* rightNode = new TreeNode(val);
                    rightNode->right = temp->right;
                    temp->right =rightNode;
                }
                
                if(temp->left) q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            depth--;
            if(depth == 1) break;
        }
        return root;
    }
};