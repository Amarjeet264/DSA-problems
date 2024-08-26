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
    vector<TreeNode*>all(int n){
        if(n%2==0){
            return {};
        }
        if(n==1){
            TreeNode* naya = new TreeNode(0);
            return {naya};
        }
        vector<TreeNode*>res;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*>left = all(i);
            vector<TreeNode*>right = all(n-i-1);
            for(auto it:left){
                for(auto x:right){
                    TreeNode* root = new TreeNode(0);
                    root->left = it;
                    root->right = x;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return all(n);
    }
};