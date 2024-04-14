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
    bool isleaf(TreeNode* root){
        if(!root->left&&!root->right){
            return true;
        }
        return false;
    }
    void summ(TreeNode* root,int &sum){
        if(!root){
            return;
        }
        if(root->left&&isleaf(root->left)){
            sum+=root->left->val;
        }
        summ(root->left,sum);
        summ(root->right,sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        summ(root,sum);
        return sum;
    }
};