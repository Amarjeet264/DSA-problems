class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int cnt=0;
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            cnt+=1;
            if(x>1)pq.push(x-1);
            if(y>1)pq.push(y-1);
        }
        return cnt;
    }
};