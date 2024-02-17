class Solution {
    unordered_map<int,int>mp;
    int cnt=0;
    vector<int>vec;
    void count(int n,int i){
        if(i>=n+1){
            cnt++;
            return ;
        }
        // cout<<i<<" ";
        // int cnt=0;
        for(int j=1;j<=n;j++){
            if((i%j==0||j%i==0)&&vec[j]==0){
                // cout<<i<<" "<<j<<" ";
                // mp[j]++;
                vec[j]=i;
                count(n,i+1);
                vec[j]=0;
                // mp[j]--;
            }
        }
        // return cnt;
    }
public:
    int countArrangement(int n) {
        vec.resize(n+1);
        count(n,1);
        return cnt;
    }
};