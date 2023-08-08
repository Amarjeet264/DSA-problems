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
    int ans=0;
    unordered_map<int,int>mp;
    void find(TreeNode* root,int lev,int prevlev){
        if(!root){
            return ;
        }
        if(mp.find(lev)==mp.end()){
            ans=root->val;
            mp[lev]++;
        }
        find(root->left,lev+1,lev);
        find(root->right,lev+1,lev);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        find(root,0,-1);
        return ans;

    }
};