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
    int deepestLeavesSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        int sum=root->val;
        while(!q.empty()){
            int size=q.size();
            // vector<int>x;
            int x=0;
            for(int i=0;i<size;i++){
                TreeNode* ni=q.front();
                // x.push_back(ni->val);
                q.pop();
                if(ni->left){
                    q.push(ni->left);
                    x+=(ni->left->val);
                }
                if(ni->right){
                    q.push(ni->right);
                    x+=(ni->right->val);
                }
            }
            // ans.push_back(x);
            if(x!=0)sum=x;
        }
        return sum;
    }
};