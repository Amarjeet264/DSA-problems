class Solution {
    int bfs(int src, int dst, vector<int> adj[], int n) {
        vector<int> dis(n, INT_MAX); // Initialize distances to infinity
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Start BFS
        dis[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            // If we reach the destination, return the distance
            if (node == dst) return d;
            
            // Relax neighbors
            for (auto it : adj[node]) {
                if (dis[node] + 1 < dis[it]) {
                    dis[it] = dis[node] + 1;
                    pq.push({dis[it], it});
                }
            }
        }
        return -1; // If destination is unreachable
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> adj[n];
        
        // Build the initial graph
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }
        
        vector<int> ans;
        
        // Process each query
        for (const auto& query : queries) {
            adj[query[0]].push_back(query[1]); // Add the new edge
            int x = bfs(0, n - 1, adj, n);     // Calculate shortest distance
            ans.push_back(x);                  // Store the result
        }
        
        return ans;
    }
};
