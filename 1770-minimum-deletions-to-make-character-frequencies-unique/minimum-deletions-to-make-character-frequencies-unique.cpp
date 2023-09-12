class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        unordered_set<int>st;
        int cnt=0;
        for(auto it:mp){
            int freq=it.second;
            while(freq>0&&st.find(freq)!=st.end()){
                freq--;
                cnt++;
            }
            st.insert(freq);
        }
        return cnt;
    }
};