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
    int maxi=INT_MIN;
    int path(TreeNode* root){
        if(!root){
            return 0;
        }
        int left=path(root->left);
        int right=path(root->right);
        maxi=max(maxi,max(root->val+left+right,max(root->val+left,max(root->val+right,root->val))));
        return max(root->val,max(root->val+left,root->val+right));
    }
public:
    int maxPathSum(TreeNode* root) {
        // int x=path(root);
        // int l=path(root->left);
        // int r=path(root->right);
        // cout<<x<<" "<<l<<" "<<r<<" ";
        // return max(x,max(root->val+l,max(root->val+r,max(l,max(r,root->val)))));
        path(root);
        return maxi;
    }
};