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
    bool is_palindrome(vector<int> &freq){
        int cnt =0;
        for(int i=0; i<10; i++){
            if(freq[i] & 1){
                cnt++;
            }
        }
        return(cnt<=1);
    }
    
    void helper(TreeNode* node, int &ans, vector<int>&freq){
        if(node==NULL) return;
        freq[node->val]++;
        if(node->left == NULL && node->right == NULL){
            if(is_palindrome(freq)){
                ans++;
            }
            freq[node->val]--;
            return;
        }
        helper(node->left,ans,freq);
        helper(node->right,ans,freq);
        freq[node->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        vector<int> freq(10);
        helper(root,ans,freq);
        return ans;
    }
};