class Solution {
public:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool bfs(vector<vector<int>>&aag,vector<vector<int>>&mere){
        for(int i=0;i<aag.size();i++){
            for(int j=0;j<aag[0].size();j++){
                mere[i][j]=aag[i][j]-mere[i][j];
            }
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>vis(aag.size(),vector<int>(aag[0].size(),0));
        vis[0][0]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;  
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow==aag.size()-1&&ncol==aag[0].size()-1&&mere[nrow][ncol]>=0){
                  return 1;
                } 
                if(nrow>=0&&ncol>=0&&nrow<aag.size()&&ncol<aag[0].size()&&vis[nrow][ncol]==0&&mere[nrow][ncol]>0){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        return 0;
    }
    bool poss(int min,vector<vector<int>>grid){
        
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({0,{i,j}});
                }

            }
        }
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if(dis==min)continue;
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0&&ncol>=0&&nrow<grid.size()&&ncol<grid[0].size()&&grid[nrow][ncol]==0){
                    grid[nrow][ncol]=1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }

        vector<vector<int>>aag(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        vector<vector<int>>mere(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        q.push({0,{0,0}});
        mere[0][0]=0;

        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0&&ncol>=0&&nrow<grid.size()&&ncol<grid[0].size()&&grid[nrow][ncol]==0&&mere[nrow][ncol]>dis+1){
                    mere[nrow][ncol]=dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    aag[i][j]=0;
                    q.push({0,{i,j}});
                }
                else if(grid[i][j]==2){
                    aag[i][j]=-1;
                }
            }
        }

        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0&&ncol>=0&&nrow<grid.size()&&ncol<grid[0].size()&&grid[nrow][ncol]==0&&aag[nrow][ncol]>dis+1){
                    aag[nrow][ncol]=dis+1;
                    q.push({dis+1,{nrow,ncol}});
                } 
            }
        }
        return bfs(aag,mere);
    }

    int maximumMinutes(vector<vector<int>>& a) {
        // if(!poss(0,a))return -1;
        int n=a.size(),m=a[0].size();
        int l=-1,r=n*m+100,ans=-1;
        while(r-l>1){
            int m=l+(r-l)/2;
            if(poss(m,a)) ans=m,l=m;
            else r=m;
        }
        if(ans>=n*m) return 1000000000;
        return ans;
    }
};