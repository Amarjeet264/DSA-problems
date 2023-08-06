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
    int cnt=0;
    vector<int> find(TreeNode* root,int d){
        if(!root){
            return {0};
        }
        if(!root->left&&!root->right){
            return {1};
        }
        vector<int>l=find(root->left,d);
        vector<int>r=find(root->right,d);
        for(int i=0;i<l.size();i++){
            for(int j=0;j<r.size();j++){
                if(l[i]+r[j]<=d&&l[i]>0&&r[j]>0){
                    cnt++;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<l.size();i++){
            if(l[i]<d&&l[i]>0){
                ans.push_back(l[i]+1);
            }
        }
        for(int i=0;i<r.size();i++){
            if(r[i]<d&&r[i]>0){
                ans.push_back(r[i]+1);
            }
        }
        return ans;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        find(root,distance);
        return cnt;
    }
};