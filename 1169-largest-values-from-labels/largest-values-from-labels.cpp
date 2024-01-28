class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int,int>>vec;
        for(int i=0;i<values.size();i++){
            vec.push_back({values[i],labels[i]});
        }
        sort(vec.rbegin(),vec.rend());
        unordered_map<int,int>mp;
        int i=0;
        int sum=0;
        int cnt=0;
        while(i<values.size()){
            if(mp[vec[i].second]<useLimit&&cnt<numWanted){
                sum+=vec[i].first;
                mp[vec[i].second]++;
                cnt++;
            }
            i++;
        }
        return sum;
    }
};