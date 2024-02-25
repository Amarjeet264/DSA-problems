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
    TreeNode* removee(TreeNode* root,int target){
        if(!root){
            return nullptr;
        }
        if(!root->left&&!root->right&&root->val==target){
            return nullptr;
        }
        TreeNode* left=removee(root->left,target);
        TreeNode* right=removee(root->right,target);
        if(!left&&!right){
            root->left=nullptr;
            root->right=nullptr;
            if(root->val==target)return nullptr;
            return root;
        }
        if(left){
            if(!right)root->right=nullptr;
            return left;
        }
        else if(right){
            if(!left){
                root->left=nullptr;
            }
            return right;
        }
        return root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root->left&&!root->right&&root->val==target)return nullptr;
        removee(root,target);
        if(!root->left&&!root->right&&root->val==target)return nullptr;
        return root;
    }
};