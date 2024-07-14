class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        vector<pair<int,int>>vec;
        for(int i=0;i<plant.size();i++){
            vec.push_back({plant[i],grow[i]});
        }
        auto lambda=[](pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        };
        sort(vec.begin(),vec.end(),lambda);
        int maxiAns = 0;
        int prevPlantingDay = 0;
        for(int i=0;i<vec.size();i++){
            int timeToPlant = vec[i].first;
            int timeToGrow = vec[i].second;
            prevPlantingDay += timeToPlant;
            maxiAns = max(maxiAns,prevPlantingDay + timeToGrow);
        }
        return maxiAns;
    }
};