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
    int maxiiii(TreeNode* root,int mini,int maxi){
        if(!root){
            return 0;
        }
        
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        cout<<mini<<" "<<maxi<<" ";
        if(!root->left&&!root->right){
            return maxi-mini;
        }
        int lef=maxiiii(root->left,mini,maxi);
        int righ=maxiiii(root->right,mini,maxi);
        return max(lef,righ);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return maxiiii(root,INT_MAX,INT_MIN);
    }
};