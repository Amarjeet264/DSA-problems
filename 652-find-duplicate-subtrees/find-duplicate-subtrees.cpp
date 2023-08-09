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
    unordered_map<string,int>mp;
    vector<TreeNode*>ans;
    string find(TreeNode* root){
        string sl="";
        string sr="";
        string curr=to_string(root->val);
        if(root->left){
            sl = find(root->left);
        }
        if(root->right){
            sr = find(root->right);
        }
        string t=curr+"l"+sl+"r"+sr;
        mp[t]++;
        if(mp[t]==2){
            ans.push_back(root);
        }
        return t;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        find(root);
        return ans;
    }
};