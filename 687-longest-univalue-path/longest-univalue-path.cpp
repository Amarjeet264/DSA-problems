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
    int maxi=0;
    int call(TreeNode* root){
        if(!root){
            return 0;
        }
        if(!root->left&&!root->right){
            return 0;
        }
        int left=call(root->left);
        int right=call(root->right);
        if(root->left&&root->right){
            if(root->val==root->left->val&&root->val==root->right->val){
                maxi=max(maxi,2+left+right);
                return 1+max(left,right);
            }
            else{
                if(root->val==root->left->val){
                    maxi=max(maxi,1+left);
                    return 1+left;
                }
                else if(root->right->val==root->val){
                    maxi=max(maxi,1+right);
                    return 1+right;
                }
                else{
                    return 0;
                }
            }
        }
        if(root->left){
            if(root->val==root->left->val){
                maxi=max(maxi,1+left);
                return 1+left;
            }
            else{
                // maxi=max(maxi,1);
                return 0;
            }
        }
        if(root->right){
            if(root->val==root->right->val){
                maxi=max(maxi,1+right);
                return 1+right;
            }
            else{
                // maxi=max(maxi,1);
                return 0;
            }
        }
        return 0;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        call(root);
        if(maxi==0)return 0;
        return maxi;
    }
};