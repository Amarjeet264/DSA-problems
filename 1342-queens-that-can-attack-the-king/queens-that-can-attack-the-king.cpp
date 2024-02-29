class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>>ans;
        map<vector<int>,int>mp;
        for(int i=0;i<queens.size();i++){
            mp[queens[i]]++;
        }
        int row=king[0];
        int col=king[1];
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0&&j==0)continue;
                int nrow=row+i;
                int ncol=col+j;
                while(nrow>=0&&ncol>=0&&nrow<8&&ncol<8){
                    if(mp.find({nrow,ncol})!=mp.end()){
                        ans.push_back({nrow,ncol});
                        mp.erase({nrow,ncol});
                        break;
                    }
                    nrow=nrow+i;
                    ncol=ncol+j;
                }
            }
        }
        return ans;
    }
};