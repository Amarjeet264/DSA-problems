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
    map<int,vector<pair<int,int>>>mp;
    void find(TreeNode* root,int lev,int row){
        if(!root){
            return;
        }
        mp[lev].push_back({row,root->val});
        find(root->left,lev-1,row+1);
        find(root->right,lev+1,row+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        find(root,0,0);
        for(auto it:mp){
            sort(it.second.begin(),it.second.end());
            vector<int>temp;
            for(auto i:it.second){
                temp.push_back({i.second});
            }
            ans.push_back(temp);
        }
        return ans;
    }
};