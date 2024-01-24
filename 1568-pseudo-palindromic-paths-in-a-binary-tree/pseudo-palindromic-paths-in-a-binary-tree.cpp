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
    int count(TreeNode* root,vector<int>vis){
        if(!root){
            return 0;
        }
        vis[root->val]++;
        if(!root->left&&!root->right){
            int cnt=0;
            for(int i=1;i<=9;i++){
                if(vis[i]%2!=0){
                    cnt++;
                }
            }
            if(cnt<=1){
                return 1;
            }
            return 0;
        }
        int left=count(root->left,vis);
        int right=count(root->right,vis);

        return left+right;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
       vector<int>vis(10,0);
       return count(root,vis);
    }
};