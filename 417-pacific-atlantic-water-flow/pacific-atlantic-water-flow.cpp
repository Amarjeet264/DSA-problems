class Solution {
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    void sbposs(vector<vector<int>>&ocean,int row,int col,vector<vector<int>>&heights){
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0&&nr<heights.size()&&nc>=0&&nc<heights[0].size()&&ocean[nr][nc]!=1&&heights[nr][nc]>=heights[row][col]){
                ocean[nr][nc]=1;
                sbposs(ocean,nr,nc,heights);

            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>atlas(n,vector<int>(m,-1));
        vector<vector<int>>paci(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0){
                    paci[i][j]=1;
                }
                if(i==n-1||j==m-1){
                    atlas[i][j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(paci[i][j]==1){
                    sbposs(paci,i,j,heights);
                }
                if(atlas[i][j]==1){
                    sbposs(atlas,i,j,heights);
                }
            }
        }
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(paci[i][j]==1&&atlas[i][j]==1){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};