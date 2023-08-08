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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*>q;
        q.push(root);
        bool ha=false;
        int distance=1;
        TreeNode* naya=new TreeNode(val);
        if(depth==1){
            naya->left=root;
            return naya;
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                TreeNode* l=node->left;
                TreeNode* r=node->right;
                q.pop();
                if(distance==depth-1){
                    TreeNode* naya1=new TreeNode(val);
                    node->left=naya1;
                    naya1->left=l;
                    TreeNode* naya2=new TreeNode(val);
                    node->right=naya2;
                    naya2->right=r;
                    ha=true;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            distance++;
            if(ha==true)break;
        }
        return root;
    }
};