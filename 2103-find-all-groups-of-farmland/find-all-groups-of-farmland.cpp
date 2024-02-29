class Solution {
    int n, m;
    int dr[4] = {-1, 0, 0, 1};
    int dc[4] = {0, -1, 1, 0};
    
    void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& land, vector<int>& farmland) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        farmland = {i, j, i, j}; // Initialize farmland with current cell
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; ++k) {
                int r = row + dr[k];
                int c = col + dc[k];
                if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && land[r][c] == 1) {
                    q.push({r, c});
                    vis[r][c] = 1;
                    farmland[2] = max(farmland[2], r); // Update bottom-right row index
                    farmland[3] = max(farmland[3], c); // Update bottom-right column index
                }
            }
        }
    }
    
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (land[i][j] == 1 && !vis[i][j]) {
                    vector<int> farmland;
                    bfs(i, j, vis, land, farmland);
                    ans.push_back(farmland);
                }
            }
        }
        
        return ans;
    }
};
