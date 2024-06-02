class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>ball;
        unordered_map<int,int>col;
        vector<int>ans(queries.size());
        int count=0;
        for(int i=0;i<queries.size();i++){
            int ballno=queries[i][0];
            int color=queries[i][1];
            int prevcolorofball=ball[ballno];
            col[prevcolorofball]--;
            if(col[prevcolorofball]==0){
                count--;
                col.erase(prevcolorofball);
            }
            if(col.find(color)==col.end())count++;
            ball[ballno]=color;
            col[color]++;
            ans[i]=count;
        }
        return ans;
    }
};