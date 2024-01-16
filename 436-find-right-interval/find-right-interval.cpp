class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int>ans;
        int n=intervals.size();
        unordered_map<int,int>mp;
        vector<int>vec;
        for(int i=0;i<n;i++){
            vec.push_back(intervals[i][0]);
            mp[intervals[i][0]]=i;
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            int x=lower_bound(vec.begin(),vec.end(),intervals[i][1])-vec.begin();
            int ele=-1;
            if(x!=n){
                ele=vec[x];
                ans.push_back(mp[ele]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};