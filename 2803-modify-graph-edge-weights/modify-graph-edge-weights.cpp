class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dst, int target) {
        vector<pair<int,int>>adj[n];
        vector<vector<int>>mat(n,vector<int>(n,INT_MAX));
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            mat[u][v]=wt;
            mat[v][u]=wt;
           if(wt==-1){
              edges[i][2] = 2e9;
           }
        }
        vector<int>dist1(n,INT_MAX);
        priority_queue<pair<int,int>>pq;
        pq.push({0,src});
        dist1[src] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            for(auto it:adj[curr]){
                int adjNode = it.first;
                int wt = it.second;
                if(d+wt<dist1[adjNode]&&wt!=-1){
                    dist1[adjNode] = d+wt;
                    pq.push({d+wt,adjNode});
                }
            }
        }
        if(dist1[dst]<target){
            return {};
        }
        if(dist1[dst]==target){
            return edges;
        }
        vector<int>dist2(n,INT_MAX);
        pq.push({0,src});
        vector<int>par(n);
        par[src] = -1;
        while(!pq.empty()){
            int d = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            for(auto it:adj[curr]){
                int adjNode = it.first;
                int wt = it.second;
                if(d+abs(wt)<dist2[adjNode]){
                    par[adjNode] = curr;
                    dist2[adjNode] = d+abs(wt);
                    pq.push({d+abs(wt),adjNode});
                }
            }
        }
        if(dist2[dst]>target){
            return {};
        }
        int extra = target;
        for(int u = dst;u!=src;u=par[u]){
            int v = par[u];
            if(mat[u][v]==-1){
                mat[u][v] = mat[v][u] = 1;
                int canGive = max(0,extra-dist1[v]-1);
                if(canGive>0){
                    mat[u][v]+=canGive;
                    mat[v][u] = mat[u][v];
                    break;
                }
            }
            extra -= mat[u][v];
        }
        for(auto &it:edges){
            if(mat[it[0]][it[1]]!=-1){
                it[2] = mat[it[0]][it[1]];
            }
        }
        return edges;
    }
};