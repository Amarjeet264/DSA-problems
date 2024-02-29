class Solution {
        vector<int>vis;
        int maxi=0;
        int calc(vector<vector<int>>& stu,vector<vector<int>>&men){
            int score=0;
            // for(int i=0;i<stu.size();i++){
            //     cout<<vis[i]<<" ";
            // }
            // if(vis[0]!=0||vis[1]!=1||vis[2]!=2)return 0;
            for(int i=0;i<stu.size();i++){
                // cout<<i<<" ";
                // cout<<vis[i]<<"      ";
                for(int j=0;j<stu[i].size();j++){
                    if(stu[i][j]==men[vis[i]][j]){
                        score++;
                    }
                }
                // cout<<score<<endl;
            }
            return score;
        }
        void call(vector<vector<int>>& stu,vector<vector<int>>&men,int i,vector<int>&vec){
            // cout<<i<<" ";
            if(i>=vis.size()){
                maxi=max(maxi,calc(stu,men));
                return;
            }
            for(int j=0;j<men.size();j++){
                if(vec[j]==-1){
                    vis[i]=j;
                    vec[j]=1;
                    call(stu,men,i+1,vec);
                    vis[i]=-1;
                    vec[j]=-1;
                }
            }
        }
public:
    int maxCompatibilitySum(vector<vector<int>>& stu, vector<vector<int>>& men) {
        int n=stu.size();
        vis.resize(n,-1);
        vector<int>vec(n,-1);
        call(stu,men,0,vec);
        return maxi;
    }
};