class Solution {
    vector<vector<int>>dir={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    void bfs(int x,int y ,int idx,vector<vector<int>>&pos, vector<vector<int>>&minDis,int n){
        vector<vector<int>>vec(50,vector<int>(50,1e9));
        queue<pair<int,int>>q;
        q.push({x,y});
        vec[x][y] = 0;
        while(!q.empty()){
            int px = q.front().first;
            int py = q.front().second;
            q.pop();
            for(int i = 0;i<8;i++){
                int nx = px+dir[i][0];
                int ny = py+dir[i][1];
                if(nx>=0&&nx<50&&ny>=0&&ny<50&&vec[nx][ny]>vec[px][py]+1){
                    vec[nx][ny] = vec[px][py] +1;
                    q.push({nx,ny});
                }
            }
        }
        for(int i = 0;i<n;i++){
            int ix = pos[i][0];
            int iy = pos[i][1];
            minDis[idx][i] = vec[ix][iy];
        }
    }
    int solve(int alice,vector<vector<int>>&pos,vector<vector<int>>&minDis,int n,int mask,int idx,vector<vector<vector<int>>>&dp){
        if(mask==0){
            return 0;
        }
        if(dp[idx][mask][alice]!=-1){
            return dp[idx][mask][alice];
        }
        int res = (alice==1?-1:1e9);
        for(int i = 1;i<=n;i++){
            if((mask & (1<<(i-1)))!=0){
                if(alice){
                    res = max(res,minDis[idx][i]+solve(0,pos,minDis,n,mask^(1<<(i-1)),i,dp));
                }
                else{
                    res = min(res,minDis[idx][i]+solve(1,pos,minDis,n,mask^(1<<(i-1)),i,dp));
                }
            }
        }
        return dp[idx][mask][alice] = res;
    }
public:
    int maxMoves(int kx, int ky,vector<vector<int>>& positions) {
        vector<vector<int>>pos;
        pos.push_back({kx,ky});
        for(auto it:positions){
            pos.push_back(it);
        }
        int n = pos.size();
        vector<vector<int>>minDis(n+1,vector<int>(n+1));
        for(int i=0;i<n;i++){
            int x = pos[i][0];
            int y = pos[i][1];
            bfs(x,y,i,pos,minDis,n);
        }
        int alice = 1;
        int mask = pow(2,n-1)-1;
        // int x = pow(2,16)-1;
        vector<vector<vector<int>>>dp(50,vector<vector<int>>(mask+1,vector<int>(2,-1)));
        return solve(alice,pos,minDis,n,mask,0,dp);
    }
};