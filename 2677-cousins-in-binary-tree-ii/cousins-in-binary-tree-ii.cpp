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
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>vec;
        queue<TreeNode*>q;
        q.push(root);
        vec.push_back(root->val);
        while(!q.empty()){
            int sz=q.size();
            int sum=0;
            for(int i=0;i<sz;i++){
                TreeNode* fr=q.front();
                q.pop();
                if(fr->left){
                    q.push(fr->left);
                    sum+=fr->left->val;
                }
                if(fr->right){
                    q.push(fr->right);
                    sum+=fr->right->val;
                }
            }
            vec.push_back(sum);
        }
        int lev=0;
        q.push(root);
        root->val=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* fr=q.front();
                q.pop();
                if(fr->left){
                    q.push(fr->left);
                }
                if(fr->right){
                    q.push(fr->right);
                }
                if(lev==0){
                    if(fr->left)fr->left->val=0;
                    if(fr->right)fr->right->val=0;
                }
                if(fr->left&&fr->right&&lev>0){
                    int x=vec[lev+1]-fr->left->val-fr->right->val;
                    fr->left->val=x;
                    fr->right->val=x;
                }
                else if(fr->left&&lev>0){
                    int x=vec[lev+1]-fr->left->val;
                    fr->left->val=x;
                }
                else if(fr->right&&lev>0){
                    int x=vec[lev+1]-fr->right->val;
                    fr->right->val=x;
                }
            }
            lev++;
        }
        return root;
    }
};