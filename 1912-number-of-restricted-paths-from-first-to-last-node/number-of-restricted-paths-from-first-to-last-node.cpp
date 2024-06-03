#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

class Solution {
    vector<int> dis;
    vector<int> dp;
    int mod = 1e9 + 7;

    // Function to perform DFS and count restricted paths
    int countPaths(vector<pair<int, int>> adj[], int node, int target) {
        if (node == target) return 1;  // If we've reached the target, there's one path
        if (dp[node] != -1) return dp[node];  // Return the cached result

        int result = 0;

        for (auto& [next, weight] : adj[node]) {
            if (dis[node] > dis[next]) {  // Only move to nodes closer to the target
                result = (result + countPaths(adj, next, target)) % mod;
            }
        }

        return dp[node] = result;  // Cache and return the result
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n + 1];
        for (auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }

        // Initialize distance vector with infinity
        dis.resize(n + 1, INT_MAX);
        dp.resize(n + 1, -1);

        // Dijkstra's algorithm to find the shortest path from node `n` to all nodes
        dis[n] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, n);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // if (d > dis[u]) continue;

            for (auto& [v, w] : adj[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.emplace(dis[v], v);
                }
            }
        }

        return countPaths(adj, 1, n);
    }
};
