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
    int suff(TreeNode* root,int limit,int sum){
        if(!root){
            return -1e6;
        }
        if(!root->left&&!root->right){
            return root->val;
        }
        int l=root->val+suff(root->left,limit,sum+root->val);
        if(sum+l<limit){
            root->left=nullptr;
            // return ;
        }
        int r=root->val+suff(root->right,limit,sum+root->val);
        if(sum+r<limit){
            root->right=nullptr;
            // return 0;
        }
        return max(l,r);
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int x=suff(root,limit,0);
        if(x<limit){
            return nullptr;
        }
        return root;
    }
};