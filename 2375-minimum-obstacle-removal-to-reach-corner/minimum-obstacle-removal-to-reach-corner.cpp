class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        pq.push({0, {0, 0}});
        cost[0][0] = 0;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int currentCost = current.first;
            int r = current.second.first;
            int c = current.second.second;

            if (r == n - 1 && c == m - 1) {
                return currentCost;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newCost = currentCost + grid[nr][nc];
                    if (newCost < cost[nr][nc]) {
                        pq.push({newCost, {nr, nc}});
                        cost[nr][nc] = newCost;
                    }
                }
            }
        }

        return -1;
    }
};
