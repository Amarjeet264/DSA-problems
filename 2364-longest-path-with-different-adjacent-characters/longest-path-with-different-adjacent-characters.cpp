class Solution {
    int maxi=1;
    int path(vector<int>adj[],string &s,int root){
        int max1=0;
        int max2=0;
        // cout<<root<<" ";
        for(auto it:adj[root]){
            int x=path(adj,s,it);
            if(s[root]==s[it])continue;
            if(max1<x){
                max2=max1;
                max1=x;
            }
            else if(x>max2){
                max2=x;
            }
        }
        maxi=max(maxi,1+max1+max2);
        return 1+max1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        vector<int>adj[s.size()];
        // if(s.size()<=1)
        for(int i=1;i<parent.size();i++){
            adj[parent[i]].push_back(i);
        }
        path(adj,s,0);
        return maxi;
    }
};