class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        vector<vector<int>> adj(k);
        vector<vector<int>> adj1(k);
        vector<int> inr(k, 0);
        vector<int> inc(k, 0);
        
        // Construct adjacency list and in-degree for rows
        for(auto& it : row){
            adj[it[0] - 1].push_back(it[1] - 1);
            inr[it[1] - 1]++;
        }
        
        // Construct adjacency list and in-degree for columns
        for(auto& it : col){
            adj1[it[0] - 1].push_back(it[1] - 1);
            inc[it[1] - 1]++;
        }
        
        vector<int> r(k, -1);
        vector<int> c(k, -1);
        queue<int> q;
        
        // Topological sort for rows
        for(int i = 0; i < k; i++) {
            if(inr[i] == 0) {
                q.push(i);
            }
        }
        int idx = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            r[node] = idx++;
            for(auto it : adj[node]) {
                inr[it]--;
                if(inr[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // Check if topological sort was possible for rows
        if(idx != k) return {};  // return empty matrix if cycle is detected
        
        // Topological sort for columns
        for(int i = 0; i < k; i++) {
            if(inc[i] == 0) {
                q.push(i);
            }
        }
        idx = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            c[node] = idx++;
            for(auto it : adj1[node]) {
                inc[it]--;
                if(inc[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // Check if topological sort was possible for columns
        if(idx != k) return {};  // return empty matrix if cycle is detected
        
        // Build the final matrix
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i = 0; i < k; i++) {
            ans[r[i]][c[i]] = i + 1;
        }
        
        return ans;
    }
};