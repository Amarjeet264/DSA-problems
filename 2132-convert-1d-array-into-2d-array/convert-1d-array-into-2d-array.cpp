class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans(m,vector<int>(n));
        int idx = 0;
        int i = 0;
        int j = 0;
        while(idx<original.size()){
            ans[i][j] = original[idx++];
            if(j==n-1){
                i++;
                j = 0;
            }
            else{
                j++;
            }
            if(i>=m&&idx<original.size())return {};
        }
        if(i!=m||j!=0){
            return {};
        }
        return ans;
    }
};