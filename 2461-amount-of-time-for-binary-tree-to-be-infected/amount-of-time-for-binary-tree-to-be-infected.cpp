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
    void make_parent(TreeNode* root,int par,vector<int>adj[]){
        if(!root){
            return ;
        }
        adj[root->val].push_back(par);
        if(par!=-1){
            adj[par].push_back(root->val);
        }
        make_parent(root->left,root->val,adj);
        make_parent(root->right,root->val,adj);
    }
    void dfs(int node , vector<int>&vis,int cnt ,int &maxi,vector<int>adj[]){
        maxi = max(maxi ,cnt);
        vis[node] = 1;
        for(auto it:adj[node]){
            if(it!=-1&&vis[it]==0){
                dfs(it,vis,cnt+1,maxi,adj);
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        int n = 1e5+1;
        vector<int>adj[n];
        make_parent(root,-1,adj);
        vector<int>vis(n);
        int maxi = 0;
        dfs(start,vis,0,maxi,adj);
        return maxi;
    }
};