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
    vector<int>sum(TreeNode* root){
        if(!root){
            return {INT_MAX,INT_MIN,0,1};
        }
        vector<int>left=sum(root->left);
        vector<int>right=sum(root->right);
        if(root->val>left[1]&&root->val<right[0]&&left[3]&&right[3]){
            maxi=max(maxi,root->val+left[2]+right[2]);
            return {min(root->val,left[0]),max(root->val,right[1]),root->val+left[2]+right[2],1};
        }
        else{
            return {min(root->val,left[0]),max(root->val,right[1]),0,0};
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        sum(root);
        return max(maxi,0);
    }
};