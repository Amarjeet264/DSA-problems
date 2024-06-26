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
    vector<int>vec;
    void balance(TreeNode* root){
        if(!root){
            return;
        }
        balance(root->left);
        vec.push_back(root->val);
        balance(root->right);
    }
    TreeNode* maketree(int i,int j){
        if(i>j){
            return nullptr;
        }
        int mid=(i+j)/2;
        TreeNode* root=new TreeNode(vec[mid]);
        // cout<<i<<" "<<j<<" "<<mid<<" "<<root->val<<endl;
        root->left=maketree(i,mid-1);
        root->right=maketree(mid+1,j);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        balance(root);
        TreeNode* newroot=maketree(0,vec.size()-1);
        return newroot;
    }
};