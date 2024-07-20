class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>>ans(rowSum.size(),vector<int>(colSum.size(),0));
        int i=0;
        int j=0;
        while(i<rowSum.size()&&j<colSum.size()){
            if(rowSum[i]<=colSum[j]){
                ans[i][j]=rowSum[i];
                colSum[j]-=rowSum[i];
                rowSum[i]=0;
                i++;
            }
            else{
                ans[i][j]=colSum[j];
                rowSum[i]-=colSum[j];
                colSum[j]=0;
                j++;
            }
        }
        return ans;
    }
};