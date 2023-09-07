class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>vis(n,0);
        vis[start]=1;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int fr=q.front();
            if(arr[fr]==0){
                return true;
            }
            q.pop();
            if(fr+arr[fr]<n&&!vis[fr+arr[fr]]){
                vis[fr+arr[fr]]=1;
                q.push(fr+arr[fr]);
            }
            if(fr-arr[fr]>=0&&!vis[fr-arr[fr]]){
                vis[fr-arr[fr]]=1;
                q.push(fr-arr[fr]);
            }
        }
        return false;
    }
};