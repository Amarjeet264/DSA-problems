class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        set<pair<int,int>>st;
        queue<pair<int,int>>q;
        for(int i=0;i<graph.size();i++){
            int set_ith_bit = (1<<i);
            q.push({i,set_ith_bit});
            st.insert({i,set_ith_bit});
        }
        int n = graph.size();
        int ans = (1<<n) - 1;
        int path = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int currNode = q.front().first;
                int currMask = q.front().second;
                if(currMask==ans){
                    return path;
                }
                q.pop();
                for(auto it:graph[currNode]){
                    int nayaMask = currMask | (1<<it);
                    if(st.find({it,nayaMask})==st.end()){
                        st.insert({it,nayaMask});
                        q.push({it,nayaMask});
                    }
                }
            }
            path++;
        }
        return path;
    }
};