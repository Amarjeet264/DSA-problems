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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int,TreeNode*>mp;
        TreeNode* ans = nullptr;
        unordered_map<int,int>mp1;
        for(int i = 0;i<desc.size();i++){
            int parent = desc[i][0];
            int child = desc[i][1];
            int isLeft = desc[i][2];
            if(mp.find(parent)==mp.end()){
                TreeNode* par = new TreeNode(parent);
                mp[parent] = par;
            }
            TreeNode* par = mp[parent];
            par = mp[parent];
            
            if(mp.find(child)==mp.end()){
                TreeNode* naya = new TreeNode(child);
                mp[child] = naya;
            }
            TreeNode* naya = mp[child];
            if(isLeft){
                par->left = naya;
            }
            else{
                par->right = naya;
            }
            mp[child] = naya;
            mp1[child]++;
        }
        for(auto it:mp){
            if(mp1.find(it.first)==mp1.end()){
                return it.second;
            }
        }
        return nullptr;
    }
};