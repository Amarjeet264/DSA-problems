class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int>pq;
        vector<int>res;
        for(int i =0;i<queries.size();i++){
            int dis = abs(queries[i][0])+abs(queries[i][1]);
            pq.push(dis);
            if(pq.size()>k){
                pq.pop();
            }
            if(pq.size()<k){
                res.push_back(-1);
            }
            else{
                res.push_back(pq.top());
            }
        }
        return res;
    }
};