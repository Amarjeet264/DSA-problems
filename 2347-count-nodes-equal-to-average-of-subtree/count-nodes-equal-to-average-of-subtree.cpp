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
    int cnt=0;
    pair<int,int> average(TreeNode* root){
        if(!root){
            return {0,0};
        }
        pair<int,int> left=average(root->left);
        pair<int,int> right=average(root->right);
        if((left.first+right.first+root->val)/(left.second+right.second+1)==root->val){
            cnt++;
        }
        return {root->val+left.first+right.first,left.second+right.second+1};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        average(root);
        return cnt;
    }
};