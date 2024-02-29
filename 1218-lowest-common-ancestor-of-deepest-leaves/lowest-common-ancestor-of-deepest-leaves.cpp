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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+max(height(root->left),height(root->right));
    }
    public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root){
            return NULL;
        }
        int lefth=height(root->left);
        int righth=height(root->right);
        if(lefth==righth){
            return root;
        }
        else{
            if(lefth>righth){
                return lcaDeepestLeaves(root->left);
            }
            else{
                return lcaDeepestLeaves(root->right);
            }
        }
    }
};