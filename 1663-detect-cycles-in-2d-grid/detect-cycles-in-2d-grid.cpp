class Solution {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool dfs(int r, int c, int pr, int pc, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && !(nr == pr && nc == pc)) {
                if (grid[nr][nc] == grid[r][c]) {
                    if (vis[nr][nc] || dfs(nr, nc, r, c, vis, grid)) return true;
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && dfs(i, j, -1, -1, vis, grid)) return true;
            }
        }
        return false;
    }
};
