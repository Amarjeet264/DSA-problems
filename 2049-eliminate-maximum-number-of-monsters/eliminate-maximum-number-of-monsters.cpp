class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<pair<double,pair<int,int>>>vec;
        for(int i=0;i<dist.size();i++){
            double x=(double)dist[i]/speed[i];
            vec.push_back({x,{dist[i],speed[i]}});
        }
        if(vec[0].first==0)return 0;
        priority_queue<double,vector<double>,greater<double>>pq;
        for(auto it:vec){
            pq.push(it.first);
        }
        int  time=0;
        int cnt=0;
        while(!pq.empty()){
            if(pq.top()>time){
                pq.pop();
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