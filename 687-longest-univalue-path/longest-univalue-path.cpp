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
    int maxAns = 1;
    pair<int,int>solve(TreeNode* root){
        if(!root){
            return {0,INT_MIN};
        }
        pair<int,int>left = solve(root->left);
        pair<int,int>right = solve(root->right);
        pair<int,int>res = {1,root->val};
        if(root->val==left.second&&root->val==right.second){
            maxAns = max(maxAns,1+left.first+right.first);
            res.first = 1 + max(left.first,right.first);
        }
        else if(root->val==left.second){
            maxAns = max(maxAns,1+left.first);
            res.first = 1 + left.first;
        }
        else if(root->val == right.second){
            maxAns = max(maxAns,1+right.first);
            res.first = 1+right.first;
        }
        return res;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root){
            return 0;
        }
        solve(root);
        return maxAns-1;
    }
};