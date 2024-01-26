class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        vector<int>ans;
        for(int i=0;i<capacity.size();i++){
            if(rocks[i]<=capacity[i]){
                ans.push_back(capacity[i]-rocks[i]);
            }
        }
        int cnt=0;
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(ans[i]<=add){
                cnt++;
                add-=ans[i];
            }
        }
        return cnt;
    }
};