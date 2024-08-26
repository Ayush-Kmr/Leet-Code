/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>ans;
    void solve(Node* root){
        for(Node*child: root->children){
            ans.push_back(child->val);
            solve(child);
        }
    }
    vector<int> preorder(Node* root) {
        if(!root) return ans;
        ans.push_back(root->val);
        solve(root);
        return ans;
    }
};