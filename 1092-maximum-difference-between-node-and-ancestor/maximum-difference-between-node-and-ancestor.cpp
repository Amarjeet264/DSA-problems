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
    int maxdiff=0;
    pair<int,int>maxa(TreeNode* root){
        if(!root){
            return {1e7,-1e7};
        }
        if(!root->left&&!root->right){
            return {root->val,root->val};
        }
        pair<int,int>left=maxa(root->left);
        pair<int,int>right=maxa(root->right);
        if(left.first!=1e7&&right.first!=1e7){
            maxdiff=max(maxdiff,max(abs(root->val-left.first),max(abs(root->val-left.second),max(abs(root->val-right.first),abs(root->val-right.second)))));
        }
        else if(left.first==1e7){
            maxdiff=max(maxdiff,max(abs(root->val-right.first),abs(root->val-right.second)));
        }
        else if(right.first==1e7){
            maxdiff=max(maxdiff,max(abs(root->val-left.first),abs(root->val-left.second)));
        }
        return {min(root->val,min(left.first,right.first)),max(root->val,max(left.second,right.second))};
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        maxa(root);
        return maxdiff;
    }
};