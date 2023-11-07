class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<pair<double,pair<int,int>>>vec;
        for(int i=0;i<dist.size();i++){
            double x=(double)dist[i]/speed[i];
            vec.push_back({x,{dist[i],speed[i]}});
        }
        sort(vec.begin(),vec.end());
        if(vec[0].first==0)return 0;
        int  time=1;
        int cnt=1;
        for(int i=1;i<vec.size();i++){
            if(vec[i].first>time){
                cnt++;
            }
            else{
                break;
            }
            time+=1;
        }
        return cnt;
    }
};