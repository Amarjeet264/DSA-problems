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
    // vector<int>v(2,0);
    vector<int>robs(TreeNode* root){
        if(!root){
            return {0,0};
        }
        vector<int>left(2,0);
        left=robs(root->left);
        vector<int>right(2,0);
        right=robs(root->right);
        vector<int>ans(2,0);
        ans[0]=root->val+left[1]+right[1];
        ans[1]=max(left[0],left[1])+max(right[0],right[1]);
        return ans;
    } 
public:
    int rob(TreeNode* root) {
        if(!root)return 0;
        vector<int>ans(2,0);
        ans=robs(root);
        return max(ans[0],ans[1]);
    }
};