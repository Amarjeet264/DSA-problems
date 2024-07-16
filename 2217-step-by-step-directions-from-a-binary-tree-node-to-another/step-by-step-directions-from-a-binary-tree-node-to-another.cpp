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
   bool findPath(TreeNode* root, int tar, string& path){

        if(root == nullptr) return false;
        if(root->val == tar) return true;

        bool left = findPath(root->left,tar,path);
        if(left){
            path += 'L';
            // return true;
        }
        bool right = findPath(root->right,tar,path);
        if(right){
            path += 'R';
            // return true;
        }
        return left||right;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string temp="";

        findPath(root,startValue,temp);

        string temp1="";
        findPath(root,destValue,temp1);
        // cout<<temp<<" "<<temp1<<" ";
        while(temp.size()>0&&temp1.size()>0&&temp[temp.size()-1]==temp1[temp1.size()-1]){
            temp.pop_back();
            temp1.pop_back();
        }
        // reverse(temp.begin(),temp.end());
        reverse(temp1.begin(),temp1.end());
        string ans="";
        while(ans.size()<temp.size()){
            ans+='U';
        }
        // cout<<root1->val;
        return ans+temp1;
    }
};