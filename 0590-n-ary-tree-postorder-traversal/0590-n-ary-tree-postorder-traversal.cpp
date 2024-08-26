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
        for(Node* child : root->children){
            solve(child);
            ans.push_back(child->val);
        }
    }
    vector<int> postorder(Node* root) {
        if(!root) return ans;
        solve(root);
        ans.push_back(root->val);
        return ans;
    }
};