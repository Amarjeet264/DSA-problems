class Solution {
public:
    int minimumBuckets(string h) {
        int n=h.size();
        unordered_map<int,int>mp;
        int cnt=0;
        for(int i=0;i<h.size();i++){
            if(h[i]=='H'){
                if(mp[i+1]>0||mp[i-1]>0)continue;
                if(i+1<n&&h[i+1]=='.'){
                    cnt++;
                    mp[i+1]=1;
                    continue;
                }
                else if(i-1>=0&&h[i-1]=='.'){
                    cnt++;
                    continue;
                }
                else return -1;
            }
        }
        return cnt;
    }
};