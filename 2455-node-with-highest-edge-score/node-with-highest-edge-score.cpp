class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long>score(edges.size(),0);
        for(int i=0;i<edges.size();i++){
            score[edges[i]]+=i;
        }
        long long maxi=0;
        int ans=-1;
        for(int i=0;i<edges.size();i++){
            if(score[i]>maxi){
                maxi=score[i];
                ans=i;
            }
        }
        return ans;
    }
};