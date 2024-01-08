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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int maxi=0;
        while(!q.empty()){
            int sz=q.size();
            int lef=0;
            int rig=0;
            long long mini=q.front().second;
            for(int i=0;i<sz;i++){
                TreeNode* fr=q.front().first;
                long long wid=q.front().second;
                if(i==0){
                    lef=wid;
                }
                if(i==sz-1){
                    rig=wid;
                }
                q.pop();
                wid=wid-mini;
                if(fr->left){
                    q.push({fr->left,2*wid+1});
                }
                if(fr->right){
                    q.push({fr->right,2*wid+2});
                }
            }
            maxi=max(maxi,rig-lef+1);
        }
        return maxi;
    }
};