class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a)
        pq.push({a,'a'});
        if(b)
        pq.push({b,'b'});
        if(c)
        pq.push({c,'c'});
        string ans="";
        while(pq.size()>1){
            pair<int,char>one=pq.top();
            pq.pop();
            pair<int,char>two=pq.top();
            pq.pop();
            if(one.first>=2){
                ans+=one.second;
                ans+=one.second;
                one.first-=2;
            }
            else{
                ans+=one.second;
                one.first-=1;
            }
            if(two.first>=2&&one.first<=two.first){
                ans+=two.second;
                ans+=two.second;
                two.first-=2;
            }
            else{
                ans+=two.second;
                two.first-=1;
            }
            if(one.first>0)pq.push({one.first,one.second});
            if(two.first>0)pq.push({two.first,two.second});
        }
        if(!pq.empty()&&pq.top().first>=2){
            ans+=pq.top().second;
            ans+=pq.top().second;
        }
        else if(!pq.empty()){
            ans+=pq.top().second;
        }
        return ans;
    }
};