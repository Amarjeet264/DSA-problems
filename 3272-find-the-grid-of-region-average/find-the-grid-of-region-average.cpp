class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n=image.size();
        int m=image[0].size();
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        vector<vector<int>>res(n,vector<int>(m,1e9));
        vector<vector<int>>vec(n,vector<int>(m,0));
        vector<vector<int>>cnt(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j+2<m&&i+2<n){
                    vector<int>chk;
                    for(int k=i;k<i+3;k++){
                        for(int s=j;s<j+3;s++){
                            bool is=1;
                            for(int can=0;can<4;can++){
                                int nrow=k+dr[can];
                                int ncol=s+dc[can];
                                if(nrow<i||ncol<j||nrow>=i+3||ncol>=j+3)continue;
                                if(abs(nrow-k)+abs(ncol-s)==1){
                                    if(abs(image[nrow][ncol]-image[k][s])>threshold){
                                        is=0;
                                        break;
                                    }
                                }
                            }
                            if(is==1){
                                chk.push_back(image[k][s]);
                            }
                        }
                    }
                    if(chk.size()==9){
                        int med=0;
                        for(int z=0;z<9;z++){
                            med+=chk[z];
                        }
                        med=med/9;
                        for(int k=i;k<i+3;k++){
                            for(int s=j;s<j+3;s++){
                                vec[k][s]+=med;
                                cnt[k][s]++;
                                res[k][s]=vec[k][s]/cnt[k][s];
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(res[i][j]==1e9){
                    res[i][j]=image[i][j];
                }
            }
        }
        return res;
    }
};