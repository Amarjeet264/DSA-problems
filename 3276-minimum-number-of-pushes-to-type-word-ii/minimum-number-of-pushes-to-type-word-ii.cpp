class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        int ans=0;
        if(mp.size()<=8){
            return word.size();
        }
        else{
            priority_queue<int>pq;
            for(auto it:mp){
                pq.push(it.second);
            }
            int all=8;
            int mul=1;
            while(!pq.empty()){
                if(all==0){
                    all=8;
                    mul++;
                }
                ans=ans+(pq.top()*mul);
                all--;
                pq.pop();
            }
        }
        return ans;
    }
};