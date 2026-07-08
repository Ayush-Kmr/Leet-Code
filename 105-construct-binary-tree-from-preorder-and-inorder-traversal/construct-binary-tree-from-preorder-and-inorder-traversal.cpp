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
    int preIndex =0;
    TreeNode* helper(vector<int>&preorder, vector<int>&inorder, int inStart, int inEnd){
        if(inStart >inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;
        int inIndex;
        for(int i=inStart; i<inEnd; i++){
            if(inorder[i]==root->val){
                inIndex = i;
                break;
            }
        }
        root->left = helper(preorder,inorder,inStart,inIndex-1);
        root->right = helper(preorder,inorder,inIndex+1, inEnd);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* ans = helper(preorder,inorder,0,inorder.size()-1);
        return ans;
    }
};