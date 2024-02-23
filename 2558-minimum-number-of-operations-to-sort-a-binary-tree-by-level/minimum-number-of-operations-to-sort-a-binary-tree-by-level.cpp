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
    int minswap(vector<int>&arr,int n){
        vector<pair<int,int>>nums;
        for(int i=0; i<n; i++){
            nums.push_back({arr[i],i});
        }
        sort(nums.begin(),nums.end());
        int swaps=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i].second==i){
                continue;
            }
            else{
                swaps++;
                swap(nums[i],nums[nums[i].second]);
                i--;
            }
        }
        return swaps;
    }
    public:
    int minimumOperations(TreeNode* root){
        queue<TreeNode*>q;
        if(root==NULL){
            return 0;
        }
        int count1=0;
        q.push(root);
        while(!q.empty()){
            vector<int>ans;
            int size=q.size();
            for(int i=0; i<size; i++){
                TreeNode*node=q.front();
                q.pop();
                ans.push_back(node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            int k=ans.size();
            count1+=minswap(ans,k);
        }
        return count1;
        
    }
};