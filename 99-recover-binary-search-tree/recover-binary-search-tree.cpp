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
    TreeNode* first=nullptr;
TreeNode* last=nullptr;
TreeNode* mid=nullptr;
TreeNode* prev=new TreeNode(INT_MIN);
void solve(TreeNode* root){
    if(!root){
        return;
    }
    solve(root->left);
    if(prev!=nullptr&&prev->val>root->val){
        if(first==nullptr){
            first=prev;
            mid=root;
        }
        else{
            last=root;
        }
    }
    prev=root;
    solve(root->right);
}
public:
    void recoverTree(TreeNode* root) {
       solve(root);
       if(last==NULL){
           swap(first->val,mid->val);
       }
       else{
           swap(first->val,last->val);
       }
    }
};