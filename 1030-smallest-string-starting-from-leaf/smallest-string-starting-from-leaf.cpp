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
    string ans="";
    void small(TreeNode* root,string s){
        if(!root){
            return;
        }
        if(!root->left&&!root->right){
            if(ans==""){
                ans=(char)(root->val+'a')+s;
            }
            else ans=min(ans,(char)(root->val+'a')+s);
        }
        small(root->left,(char)(root->val+'a')+s);
        small(root->right,(char)(root->val+'a')+s);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        small(root,"");
        return ans;
    }
};