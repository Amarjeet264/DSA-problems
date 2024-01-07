/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* ans=new TreeNode(-1);
    TreeNode * lca(TreeNode *root,TreeNode* x,TreeNode* y){
        if(!root){
            return NULL;
        }
        if(root==x||root==y){
            return root;
        }
        TreeNode * left=lca(root->left,x,y);
        TreeNode* right=lca(root->right,x,y);
        if(left==NULL&&right==NULL){
            return NULL;
        }
        else if(left!=NULL&&right!=NULL){
            // ans=root;
            return root;
        }
        else if(left==NULL){
            return right;
        }
        else{
            return left;
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
        // return ans;
    }
};