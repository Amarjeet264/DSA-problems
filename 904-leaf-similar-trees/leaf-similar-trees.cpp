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
    void calc(TreeNode* root,vector<int> &s){
        if(!root){
            return;
        }
        if(!root->left&&!root->right){
            s.push_back(root->val);
            return;
        }
        calc(root->left,s);
        calc(root->right,s);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>s1;
        vector<int>s2;
        calc(root1,s1);
        calc(root2,s2);
        if(s1.size()!=s2.size()){
            return false;
        }
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        return true;
    }
};