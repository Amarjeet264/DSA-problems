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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);
        return left+right+1;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        unordered_map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>q;
        q.push(root);
        mp[root]=nullptr;
        TreeNode* start=nullptr;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* fr=q.front();
                q.pop();
                if(fr->val==x){
                    start=fr;
                }
                if(fr->left){
                    mp[fr->left]=fr;
                    q.push(fr->left);
                }
                if(fr->right){
                    mp[fr->right]=fr;
                    q.push(fr->right);
                }
            }
        }
        unordered_map<TreeNode*,int>vis;
        int parsz=0;
        vis[start]=1;
        if(mp[start]!=nullptr){
            vis[mp[start]]=1;
            q.push(mp[start]);
            while(!q.empty()){
                int sz=q.size();
                parsz+=sz;
                for(int i=0;i<sz;i++){
                    TreeNode* fr=q.front();
                    q.pop();
                    if(mp[fr]!=nullptr&&!vis[mp[fr]]){
                        q.push(mp[fr]);
                        vis[mp[fr]]=1;
                    }
                    if(fr->left&&!vis[fr->left]){
                        q.push(fr->left);
                        vis[fr->left]=1;
                    }
                    if(fr->right&&!vis[fr->right]){
                        q.push(fr->right);
                        vis[fr->right]=1;
                    }
                }
            }
        }
        int leftheight=0;
        if(start->left){
            leftheight=height(start->left);
        }
        int rightheight=0;
        if(start->right){
            rightheight=height(start->right);
        }
        if(parsz>leftheight+rightheight||leftheight>parsz+rightheight||rightheight>leftheight+parsz){
            return 1;
        }
        return 0;
    }
};