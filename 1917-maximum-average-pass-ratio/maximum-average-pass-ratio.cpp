class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& cla, int extra) {
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<cla.size();i++){
            pq.push({(double)(cla[i][0]+1)/(cla[i][1]+1)-(double)(cla[i][0])/(cla[i][1]),i});
        }
        while(!pq.empty()){
            // cout<<pq.top().first<<" ";
            int purana=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            if(extra>=1){
                cla[idx][0]+=1;
                cla[idx][1]+=1;
                pq.push({(double)(cla[idx][0]+1)/(cla[idx][1]+1)-(double)(cla[idx][0])/(cla[idx][1]),idx});
                extra--;
            }
            else{
                break;
            }
        }
        double x=0;
        for(int i=0;i<cla.size();i++){
            x=x+(double)cla[i][0]/cla[i][1];
        }
        return (double)x/cla.size();
    }
};