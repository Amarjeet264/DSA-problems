class Solution {
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[1]==b[1]){
            return a[0]>b[0];
        }
        return a[1]>b[1];
    }
public:
    vector<int> filterRestaurants(vector<vector<int>>& res, int vegan, int maxp, int maxd) {
        sort(res.begin(),res.end(),comp);
        vector<int>ans;
        for(int i=0;i<res.size();i++){
            if(vegan){
                if(res[i][2]==1&&res[i][3]<=maxp&&res[i][4]<=maxd){
                    ans.push_back(res[i][0]);
                }
            }
            else{
                if(res[i][3]<=maxp&&res[i][4]<=maxd){
                    ans.push_back(res[i][0]);
                }
            }
        }
        return ans;
    }
};