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
    vector<TreeNode*>ans;
    void call(TreeNode* &root,unordered_set<int>&st){
        if(!root){
            return;
        }
        call(root->left,st);
        call(root->right,st);
        if(st.find(root->val)!=st.end()){
            if(root->left)ans.push_back(root->left);
            if(root->right)ans.push_back(root->right);
            root->left=nullptr;
            root->right=nullptr;
            // delete(root);
            root=nullptr;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st;
        for(auto it:to_delete){
            st.insert(it);
        }
        call(root,st);
        if(root)ans.push_back(root);
        return ans;
    }
};