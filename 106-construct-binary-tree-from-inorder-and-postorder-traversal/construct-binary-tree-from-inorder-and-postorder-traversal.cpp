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
    int find(int x,vector<int>&inorder){
        for(int i=0;i<inorder.size();i++){
            if(x==inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>&postorder,vector<int>&inorder,int &post,int instart,int inend){
        if(instart>inend||post<0){
            return nullptr;
        }
        TreeNode* root=new TreeNode(postorder[post--]);
        int inpos=find(root->val,inorder);
        root->right=build(postorder,inorder,  post ,inpos+1,inend);
        root->left=build(postorder,inorder, post ,instart,inpos-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx=postorder.size()-1;
        return build(postorder,inorder,idx,0,inorder.size()-1);
    }
};