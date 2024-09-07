class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return dfs(root, head);
    }
    bool dfs(TreeNode* root, ListNode* head) {
        if (root == nullptr) return false;
        if (checkPath(root, head)) return true;
        return dfs(root->left, head) || dfs(root->right, head);
    }
    bool checkPath(TreeNode* root, ListNode* head) {
        if (head == nullptr) return true; 
        if (root == nullptr) return false; 
        if (root->val != head->val) return false;
return checkPath(root->left, head->next) || checkPath(root->right, head->next);
    }
};
