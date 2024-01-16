class TopVotedCandidate {
    vector<int>x;
    map<int,int>mp;
    vector<int>ans;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int mxp=-1;
        int maxi=0;
        x=times;
        for(int i=0;i<persons.size();i++){
            mp[persons[i]]++;
            if(maxi<=mp[persons[i]]){
                maxi=mp[persons[i]];
                mxp=persons[i];
            } 
            ans.push_back(mxp);
        }
    }
    int q(int t) {
        int y=upper_bound(x.begin(),x.end(),t)-x.begin()-1;
        return ans[y];
    }
};