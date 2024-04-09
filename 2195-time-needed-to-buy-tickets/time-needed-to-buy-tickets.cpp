class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        for(int i=0;i<tickets.size();i++){
            q.push({i,tickets[i]});
        }
        int cnt=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int idx=q.front().first;
                int tick=q.front().second;
                q.pop();
                tick-=1;
                cnt++;
                if(tick==0&&idx==k){
                    return cnt;
                }
                if(tick>0){
                    q.push({idx,tick});
                }
            }
        }
        return cnt;
    }
};