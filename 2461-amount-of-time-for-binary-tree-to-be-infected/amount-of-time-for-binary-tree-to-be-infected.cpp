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
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*>q;
        map<TreeNode*,TreeNode*>parent;
        q.push(root);
        TreeNode* sta=nullptr;
        while(!q.empty()){
            TreeNode* fr=q.front();
            q.pop();
            if(fr->val==start){
                sta=fr;
            }
            if(fr->left){
                parent[fr->left]=fr;
                q.push(fr->left);
            }
             if(fr->right){
                parent[fr->right]=fr;
                q.push(fr->right);
            }
        }
        queue<TreeNode*>q1;
        q1.push(sta);
        vector<int>ans;
        map<TreeNode*,int>mp;
        mp[sta]++;
        int d=0;
        while(!q1.empty()){
            int size=q1.size();
            cout<<size<<" ";
            for(int i=0;i<size;i++){
                TreeNode* fr=q1.front();
                q1.pop();
                if(parent.find(fr)!=parent.end()&&mp.find(parent[fr])==mp.end()){
                    mp[parent[fr]]++;
                    q1.push(parent[fr]);
                }
                if(fr->left&&mp.find(fr->left)==mp.end()){
                    mp[fr->left]++;
                    q1.push(fr->left);
                }
                if(fr->right&&mp.find(fr->right)==mp.end()){
                    mp[fr->right]++;
                    q1.push(fr->right);
                }
            }
            d++;
        }
        return d-1;
    }
};