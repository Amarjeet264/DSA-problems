class Solution {
public:
    int stoneGameVI(vector<int>& alice, vector<int>& bob) {
        priority_queue<pair<int,int>>pq;
        // priority_queue<pair<int,int>>pq1;
        for(int i=0;i<alice.size();i++){
            pq.push({alice[i]+bob[i],i});
            // pq1.push({bob[i],i});
        }
        int a=0;
        int b=0;
        bool first=1;
        while(!pq.empty()){
            if(first){
               a+=alice[pq.top().second]; 
            }
            else{
                b+=bob[pq.top().second];
            }
            pq.pop();
            first=!first;
        }
        if(a>b)return 1;
        if(b>a)return -1;
        return 0;
    }
};