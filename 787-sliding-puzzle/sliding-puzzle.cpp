class Solution {
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>>vec(2,vector<int>(3,0));
        vec[0][0]=1;
        vec[0][1]=2;
        vec[0][2]=3;
        vec[1][0]=4;
        vec[1][1]=5;
        vec[1][2]=0;
        // int row=-1;
        // int col=-1;
        // for(int i=0;i<2;i++){
        //     for(int j=0;j<3;j++){
        //         if(board[i][j]==0){
        //             row=i;
        //             col=j;
        //             break;
        //         }
        //     }
        // }
        map<vector<vector<int>>,int>mp;
        queue<pair<int,vector<vector<int>>>>q;
        q.push({0,board});
        mp[board]++;
        int mini=INT_MAX;
        while(!q.empty()){
            vector<vector<int>>x=q.front().second;
            int op=q.front().first;
            q.pop();
            if(vec==x){
                mini=min(mini,op);
                continue;
            }
            bool ek=0;
            vector<vector<int>>dup=x;
            for(int i=0;i<2;i++){
                for(int j=0;j<3;j++){
                    // cout<<x[i][j]<<" ";
                    if(dup[i][j]==0){
                        ek=1;
                        for(int k=0;k<4;k++){
                            int nrow=i+dr[k];
                            int ncol=j+dc[k];
                            if(nrow<0||ncol<0||nrow>=2||ncol>=3)continue;
                            swap(dup[nrow][ncol],dup[i][j]);
                            if(mp.find(dup)==mp.end()){
                                mp[dup]++;
                                // op++;
                                q.push({op+1,dup});
                            }
                            dup=x;
                        }
                        break;
                    }
                }
                if(ek){
                    break;
                }
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};