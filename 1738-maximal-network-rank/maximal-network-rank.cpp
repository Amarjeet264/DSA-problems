class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n,0);
        set<int>st[n];
        for(auto it:roads){
            indegree[it[0]]++;
            indegree[it[1]]++;
            st[it[0]].insert(it[1]);
            st[it[1]].insert(it[0]);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(st[i].find(j)==st[i].end()){
                    maxi=max(maxi,indegree[i]+indegree[j]);
                }
                else{
                    maxi=max(maxi,indegree[i]+indegree[j]-1);
                }
            }
        }
        return maxi;
    }
};