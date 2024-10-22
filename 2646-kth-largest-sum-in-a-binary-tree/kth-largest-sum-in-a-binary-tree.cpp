/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, long long k) {
        queue<TreeNode*>q;
        q.push(root);
        priority_queue<long long>pq;
        while(!q.empty()){
            long long sz = q.size();
            long long sum = 0;
            for(long long i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            pq.push(-sum);
            if(pq.size()>k){
                pq.pop();
            }
            // cout<<sum<<endl;
        }
        if(pq.size()<k)return -1;
        return -pq.top();
    }
};