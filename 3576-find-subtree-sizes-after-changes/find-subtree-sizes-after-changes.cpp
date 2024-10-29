#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        vector<int> subtree_size(n, 0);
        int root = -1;

        // Step 1: Build original adjacency list and find the root
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                root = i;
            } else {
                adj[parent[i]].push_back(i);
            }
        }

        // Step 2: Update parent links based on nearest ancestor with the same character
        // Map of last occurrence of each character in the DFS traversal path
        unordered_map<char, int> nearest_ancestor;
        updateParents(root, -1, adj, s, nearest_ancestor, parent);

        // Step 3: Build adjacency list with the updated parents
        vector<vector<int>> adj1(n);
        for (int i = 0; i < n; ++i) {
            if (parent[i] != -1) {
                adj1[parent[i]].push_back(i);
            }
        }

        // Step 4: Calculate subtree sizes with DFS from the root
        dfs(root, adj1, subtree_size);

        return subtree_size;
    }

private:
    void updateParents(int node, int par, vector<vector<int>>& adj, string& s,
                       unordered_map<char, int>& nearest_ancestor, vector<int>& parent) {
        // Save current nearest ancestor for this character and update it to current node
        int original_ancestor = nearest_ancestor.count(s[node]) ? nearest_ancestor[s[node]] : -1;
        nearest_ancestor[s[node]] = node;

        // If an ancestor with the same character exists, update the parent
        if (original_ancestor != -1 && par != -1) {
            parent[node] = original_ancestor;
        }

        // DFS to children
        for (int child : adj[node]) {
            updateParents(child, node, adj, s, nearest_ancestor, parent);
        }

        // Restore the previous ancestor in the path for backtracking
        nearest_ancestor[s[node]] = original_ancestor;
    }

    int dfs(int node, const vector<vector<int>>& adj, vector<int>& subtree_size) {
        subtree_size[node] = 1; // Count the current node
        for (int child : adj[node]) {
            subtree_size[node] += dfs(child, adj, subtree_size);
        }
        return subtree_size[node];
    }
};
