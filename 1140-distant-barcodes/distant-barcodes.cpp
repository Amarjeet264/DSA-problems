class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>mp;
        for(int i=0;i<barcodes.size();i++){
            mp[barcodes[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        if(pq.size()==1){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        while(!pq.empty()){
            int first=pq.top().second;
            int fre1=pq.top().first;
            pq.pop();
            ans.push_back(first);
            if(pq.empty())break;
            int second=pq.top().second;
            int fre2=pq.top().first;
            pq.pop();
            ans.push_back(second);
            fre1--;
            fre2--;
            if(fre1){
                pq.push({fre1,first});
            }
            if(fre2){
                pq.push({fre2,second});
            }
        }
        // ans.push_back(pq.top().second);
        return ans;
    }
};