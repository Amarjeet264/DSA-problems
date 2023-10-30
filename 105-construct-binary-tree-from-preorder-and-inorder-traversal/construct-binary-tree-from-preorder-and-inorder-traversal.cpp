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
    unordered_map<int,int>mp;
    TreeNode* build(vector<int>&pre,vector<int>&in,int &preindex,int instart,int inend){
        if(preindex>pre.size()-1||instart>inend){
            return nullptr;
        }
        TreeNode* root=new TreeNode(pre[preindex++]);
        int inroot=mp[root->val];
        root->left=build(pre,in,preindex,instart,inroot-1);
        root->right=build(pre,in,preindex,inroot+1,inend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in){
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }
        int preindex=0;
        return build(pre,in,preindex,0,in.size()-1);
    }
};