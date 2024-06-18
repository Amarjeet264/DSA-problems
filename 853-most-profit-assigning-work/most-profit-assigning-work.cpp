class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>vec;
        for(int i=0;i<profit.size();i++){
            vec.push_back({difficulty[i],profit[i]});
        }
        sort(vec.begin(),vec.end());
        sort(worker.begin(),worker.end());
        int i=0;
        int maxi=0;
        int j=0;
        int ans=0;
        for(int i=0;i<worker.size();i++){
            while(j<vec.size()&&vec[j].first<=worker[i]){
                maxi=max(maxi,vec[j].second);
                j++;
            }
            ans+=maxi;
        }
        return ans;
    }
};