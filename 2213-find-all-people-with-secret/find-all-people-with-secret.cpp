class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int first) {
        vector<pair<int,int>>adj[n];
        for(auto it:meetings){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>time(n,INT_MAX);
        time[0]=0;
        time[first]=0;
        queue<int>q;
        q.push(first);
        q.push(0);
        unordered_set<int>st;
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            st.insert(node);
            q.pop();
            for(auto it:adj[node]){
                if(time[node]>it.second){
                    continue;
                }
                else if(time[it.first]>it.second){
                    time[it.first]=it.second;
                    q.push(it.first);
                }
            }
        }
        st.insert(0);
        st.insert(first);
        // for(auto it:meetings){
        //     if(time[it[0]]<=it[2]){
        //         st.insert(it[1]);
        //     }
        //     if(time[it[1]]<=it[2]){
        //         st.insert(it[0]);
        //     }
        // }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};