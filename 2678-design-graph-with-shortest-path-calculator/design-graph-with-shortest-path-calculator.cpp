class Graph {
public:
    int x=0;
    unordered_map<int,vector<pair<int,int>>>adj;
    Graph(int n, vector<vector<int>>& edges) {
        x=n;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        queue<pair<int,int>>q;
        q.push({node1,0});
        vector<int>dist(x,INT_MAX);
        dist[node1]=0;
        while(!q.empty()){
            int fr=q.front().first;
            int d=q.front().second;
            q.pop();
            for(auto it:adj[fr]){
                if(dist[it.first]>dist[fr]+it.second){
                    dist[it.first]=dist[fr]+it.second;
                    q.push({it.first,dist[it.first]});
                }
            }
        }
        int d=dist[node2];
        return d==INT_MAX?-1:d;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */