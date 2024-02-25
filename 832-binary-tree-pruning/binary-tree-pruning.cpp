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
    bool prune(TreeNode* root){
        if(!root){
            return false;
        }
        if(!root->left&&!root->right){
            return root->val==1;
        }
        bool left=prune(root->left);
        bool right=prune(root->right);
        if(!left&&!right){
            root->left=nullptr;
            root->right=nullptr;
            return root->val==1;
        }
        if(!left){
            root->left=nullptr;
            return (root->val==1||right);
        }
        if(!right){
            root->right=nullptr;
            return root->val==1||left;
        }
        return left||right;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool x=prune(root);
        if(!x){
            return nullptr;
        }
        return root;
    }
};