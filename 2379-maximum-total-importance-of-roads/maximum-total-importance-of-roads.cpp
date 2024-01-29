class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][1]].push_back(roads[i][0]);
            adj[roads[i][0]].push_back(roads[i][1]);
        }
        vector<int>fre(n,0);
        for(int i=0;i<n;i++){
            fre[i]=adj[i].size();
        }
        sort(fre.begin(),fre.end());
        long long cnt=n;
        long long ans=0;
        for(int i=n-1;i>=0;i--){
            ans+=(fre[i]*cnt);
            cnt-=1;
        }
        return ans;
    }
};