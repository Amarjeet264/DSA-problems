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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool lev=0;
        while(!q.empty()){
            int sz=q.size();
            int prev=-1;
            if(lev==0){
                prev=INT_MIN;
            }
            else{
                prev=INT_MAX;
            }
            for(int i=0;i<sz;i++){
                TreeNode* fr=q.front();
                q.pop();
                if(lev==0){
                    if(prev>=fr->val||fr->val%2==0){
                        return false;
                    }
                }
                else if(lev==1){
                    if(prev<=fr->val||fr->val%2!=0){
                        return false;
                    }
                }
                prev=fr->val;
                if(fr->left){
                    q.push(fr->left);
                }
                if(fr->right){
                    q.push(fr->right);
                }
            }
            lev=!lev;
        }
        return true;
    }
};