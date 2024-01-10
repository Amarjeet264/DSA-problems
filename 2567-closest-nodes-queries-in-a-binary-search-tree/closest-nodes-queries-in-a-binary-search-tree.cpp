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
    vector<int>dup;
    void collect(TreeNode* root){
        if(!root){
            return;
        }
        dup.push_back(root->val);
        collect(root->left);
        collect(root->right);
    }
    int searchmin(int x){
        int low=0;
        int high=dup.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(dup[mid]<=x){
                ans=dup[mid];
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    int searchmax(int x){
        int low=0;
        int high=dup.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(dup[mid]>=x){
                ans=dup[mid];
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        collect(root);
        vector<vector<int>>ans;
        sort(dup.begin(),dup.end());
        for(int i=0;i<queries.size();i++){
            int ele=searchmin(queries[i]);
            int sele=searchmax(queries[i]);
            ans.push_back({ele,sele});
        }
        return ans;
    }
};