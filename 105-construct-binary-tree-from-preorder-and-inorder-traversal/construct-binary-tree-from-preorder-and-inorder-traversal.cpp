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
    TreeNode* build(vector<int>&pre,vector<int>&in,int preindex,int preend,int instart,int inend){
        if(preindex>preend||instart>inend){
            return nullptr;
        }
        TreeNode* root=new TreeNode(pre[preindex]);
        int inroot=mp[root->val];
        int nums=inroot-instart;
        root->left=build(pre,in,preindex+1,preend+nums,instart,inroot-1);
        root->right=build(pre,in,preindex+nums+1,preend,inroot+1,inend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in){
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }
        return build(pre,in,0,pre.size()-1,0,in.size()-1);
    }
};