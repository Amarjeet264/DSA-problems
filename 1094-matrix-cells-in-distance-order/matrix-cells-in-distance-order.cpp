class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<rows;i++){
            // vector<int>dup;
            for(int j=0;j<cols;j++){
                // ans.push_back({abs(rCenter-i),abs(cCenter-j)});
                pq.push({-(abs(rCenter-i)+abs(cCenter-j)),{i,j}});
            }
        }
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};