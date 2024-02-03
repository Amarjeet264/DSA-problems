class Solution {
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),comp);
        vector<int>vec;
        for(int i=0;i<env.size();i++){
            if(vec.size()==0){
                vec.push_back(env[i][1]);
            }
            else{
                if(env[i][1]>vec.back()){
                    vec.push_back(env[i][1]);
                }
                else{
                    int idx=lower_bound(vec.begin(),vec.end(),env[i][1])-vec.begin();
                    vec[idx]=env[i][1];
                }
            }
        }
        return vec.size();
    }
};