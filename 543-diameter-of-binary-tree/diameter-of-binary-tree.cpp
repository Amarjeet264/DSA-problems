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
    int dia(TreeNode* root,int &maxi){
        if(!root){
            return 0;
        }
        int leftdia=dia(root->left,maxi);
        int rightdia=dia(root->right,maxi);
        maxi=max(maxi,leftdia+rightdia+1);
        return 1+max(leftdia,rightdia);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        int x=dia(root,maxi);
        return max(maxi,x)-1;
    }
};