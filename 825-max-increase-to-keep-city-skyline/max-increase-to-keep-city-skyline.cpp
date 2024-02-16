class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dup(n,vector<int>(m,INT_MIN));
        for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            for(int j=0;j<m;j++){
                maxi=max(maxi,grid[i][j]);
            }
            for(int j=0;j<m;j++){
                dup[i][j]=maxi;
            }
        }
        for(int j=0;j<m;j++){
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                maxi=max(maxi,grid[i][j]);
            }
            for(int i=0;i<n;i++){
                dup[i][j]=min(dup[i][j],maxi);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=(dup[i][j])-grid[i][j];
            }
        }
        return ans;
    }
};