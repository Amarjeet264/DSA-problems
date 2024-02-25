class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottom, vector<vector<int>>& top) {
        long long maxi=0;
        for(int i=0;i<bottom.size();i++){
            for(int j=0;j<bottom.size();j++){
                if(i==j||top[j][0]>top[i][0]){
                    continue;
                }
                if(top[j][0]>=bottom[i][0]&&top[j][0]<=top[i][0]){
                    int w=top[j][0]-max(bottom[i][0],bottom[j][0]);
                    int y1=max(bottom[i][1],bottom[j][1]);
                    int y2=min(top[i][1],top[j][1]);
                    long long mini=min(y2-y1,w);
                    // cout<<i<<" "<<j<<" "<<y1<<" "<<y2<<" "<<mini<<endl;
                    if(mini<0)continue;
                    maxi=max(maxi,mini*mini);
                }
            }
        }
        return maxi;
    }
};