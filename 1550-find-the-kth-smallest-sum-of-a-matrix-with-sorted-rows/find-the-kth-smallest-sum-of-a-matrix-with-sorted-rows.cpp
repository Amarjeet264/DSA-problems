class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int>row=mat[0];
        for(int i = 1; i < mat.size(); ++i) {
            vector<int> nr;
            for(int j = 0; j < mat[i].size(); ++j) {
                for(auto n : row) {
                    nr.push_back(mat[i][j] + n);
                }
            }
            sort(nr.begin(), nr.end());
            int sz=nr.size();
            row.clear();
            for(int x = 0; x <min(k,sz) ;++x) {
                row.push_back(nr[x]);
            }
        }
        return row[k-1];
    }
};