class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return NULL;
        }
        
        // Traverse to find the node to delete
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } 
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } 
        else { // Found the node with the value equal to key
            // Case 1: No left child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // Case 2: No right child
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            else {
                // Find the rightmost node in the left subtree (in-order predecessor)
                TreeNode* r = root->left;
                while (r->right != NULL) {
                    r = r->right;
                }
                // Replace root's value with the in-order predecessor's value
                root->val = r->val;
                // Delete the in-order predecessor
                root->left = deleteNode(root->left, r->val);
            }
        }
        
        return root;
    }
};
