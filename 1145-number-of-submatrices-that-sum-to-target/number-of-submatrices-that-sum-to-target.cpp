class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<m;i++){
            vector<int>pre(n,0);
            for(int j=i;j<m;j++){
                for(int k=0;k<n;k++){
                    pre[k]+=matrix[k][j];
                }
                for(int k=0;k<n;k++){
                    int sum=0;
                    for(int s=k;s<n;s++){
                        sum+=pre[s];
                        if(sum==target){
                            ans+=1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};