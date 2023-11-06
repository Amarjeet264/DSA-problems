class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        while(i<n){
            int j=0;
            while(j<m){
                pq.push(matrix[i][j]);
                if(pq.size()>k){
                    pq.pop();
                }
                j++;
            }
            // if(pq.size()>k){
            //     pq.pop();
            // }
            i++;
        }
        return pq.top();
    }
};