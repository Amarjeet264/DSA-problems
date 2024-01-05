class Solution {
    int find(vector<int>&arr,int m){
        int maxi=0;
        for(int i=0;i<m;i++){
            if(arr[i]>arr[maxi]){
                maxi=i;
            }
        }
        return maxi;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int srow=0;
        int erow=n-1;
        while(srow<=erow){
            int midr=srow+(erow-srow)/2;;
            int maxc=find(mat[midr],m);
            if(midr==0){
                if(midr+1>erow||mat[midr][maxc]>mat[midr+1][maxc]){
                    return {midr,maxc};
                }
                else{
                    srow=midr+1;
                }
            }
            else if(midr==n-1){
                if(mat[midr][maxc]>mat[midr-1][maxc]){
                    return {midr,maxc};
                }
                else{
                    erow=midr-1;
                }
            }
            else{
                if(mat[midr][maxc]>mat[midr+1][maxc]&&mat[midr][maxc]>mat[midr-1][maxc]){
                    return {midr,maxc};
                }
                else if(mat[midr][maxc]<mat[midr-1][maxc]){
                    erow=midr-1;
                }
                else{
                    srow=midr+1;
                }
            }
        }
        return {};
    }
};