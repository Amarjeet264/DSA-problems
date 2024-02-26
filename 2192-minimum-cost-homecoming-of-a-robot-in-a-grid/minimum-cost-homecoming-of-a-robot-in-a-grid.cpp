class Solution {
public:
    int minCost(vector<int>& start, vector<int>& home, vector<int>& row, vector<int>& col) {
        // int mini=INT_MAX;
        int cnt1=0;
        int cnt2=0;
        if(home[0]>=start[0]){
            for(int i=start[0]+1;i<=home[0];i++){
                cnt1+=row[i];
            }
        }
        else{
            for(int i=start[0]-1;i>=home[0];i--){
                cnt1+=row[i];
            }
        }
        if(home[1]>=start[1]){
            for(int i=start[1]+1;i<=home[1];i++){
                cnt2+=col[i];
            }
        }
        else{
            for(int i=start[1]-1;i>=home[1];i--){
                cnt2+=col[i];
            }
        }
        return cnt1+cnt2;
    }
};