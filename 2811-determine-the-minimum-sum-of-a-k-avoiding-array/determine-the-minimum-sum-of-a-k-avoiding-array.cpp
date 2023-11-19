class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int,int>mp;
        int x=1;
        int sum=0;
        int cnt=0;
        while(cnt<n){
            if(mp.find(k-x)==mp.end()){
                sum+=x;
                mp[x]++;
                cnt++;
            }
            x++;
        }
        return sum;
    }
};