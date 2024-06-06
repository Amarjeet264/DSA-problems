class Solution {
public:
    bool isNStraightHand(vector<int>& cards, int size) {
        unordered_map<int,int>mp;
        for(int i=0;i<cards.size();i++){
            mp[cards[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto &it:mp){
            pq.push({it.first,it.second});
        }
        while(!pq.empty()){
            vector<pair<int,int>>dup;
            int prev=-1;
            int sz=size;
            while(sz--){
                int ele=pq.top().first;
                int fre=pq.top().second;
                pq.pop();
                if(prev==-1||abs(ele-prev)==1){
                    prev=ele;
                }
                else{
                    return false;
                }
                if(fre-1>0)dup.push_back({ele,fre-1});
            }
            for(int i=0;i<dup.size();i++){
                pq.push(dup[i]);
            }
        }
        return true;
    }
};