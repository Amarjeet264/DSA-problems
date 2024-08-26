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
    vector<int>ans;
    void post(Node* root){
        if(!root){
            return ;
        }
        // vector<int>vec;
        for(int i = 0;i<root->children.size();i++){
            post(root->children[i]);
            ans.push_back(root->children[i]->val);
        }
        // ans
    }
public:
    vector<int> postorder(Node* root) {
        post(root);
        if(root)ans.push_back(root->val);
        return ans;
    }
};