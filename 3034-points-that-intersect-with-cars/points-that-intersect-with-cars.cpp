class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<bool>vis(101,0);
        for(int i=0;i<nums.size();i++){
            for(int j=nums[i][0];j<=nums[i][1];j++){
                vis[j]=1;
            }
        }
        int ans=0;
        for(int i=0;i<=101;i++){
            if(vis[i]){
                ans++;
            }
        }
        return ans;
    }
};