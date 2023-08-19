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
    TreeNode* invert(TreeNode* root){
        if(!root){
            return nullptr;
        }
        if(!root->left&&!root->right){
            return root;
        }
        TreeNode* l= invert(root->left);
        TreeNode* r= invert(root->right);
        root->left=r;
        root->right=l;
        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root||(!root->left&&!root->right)){
            return root;
        }
        return invert(root);
    }
};