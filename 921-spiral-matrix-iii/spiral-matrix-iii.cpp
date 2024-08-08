class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rstart, int cstart) {
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        vector<vector<int>>ans;
        int steps = 0;
        int i = 0 ;
        ans.push_back({rstart,cstart});
        while(ans.size()<rows*cols){
            if(i==0||i==2){
                steps++;
            }
            // cout<<rstart<<" "<<cstart<<endl;
            for(int cnt = 0;cnt<steps;cnt++){
                rstart = rstart + dr[i];
                cstart = cstart + dc[i];
                if(rstart>=0&&rstart <rows&&cstart >=0&&cstart <cols){
                    ans.push_back({rstart,cstart});
                }
            }
            i=(i+1)%4;
        }
        return ans;
    }
};