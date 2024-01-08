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
    vector<string>ans;
    void allroot(TreeNode* root,string s){
        if(!root){
            return;
        }
        if(!root->left&&!root->right){
            // s+="->";
            s+=to_string(root->val);
            ans.push_back(s);
            // cout<<"gggg"<<s<<"gggg"<<endl;
            return;
        }
        allroot(root->left,s+to_string(root->val)+"->");
        allroot(root->right,s+to_string(root->val)+"->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // vector<string>ans;
        string s="";
        allroot(root,s);
        return ans;
    }
};