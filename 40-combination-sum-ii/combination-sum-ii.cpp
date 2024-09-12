class Solution {
    vector<vector<int>>soln;
    void helper(vector<int>& candidates, int target,vector<int>&curr,int ind,int sz){
        //base case
        if(target==0)soln.push_back(curr);
        if(ind==sz)return;
        //picking the value
        for(int x=ind;x<sz;x++){
            if(target>=candidates[x]){
                curr.push_back(candidates[x]);
                helper(candidates,target-candidates[x],curr,x+1,sz);
                curr.pop_back();
            }
            int temp=x;
            while(temp<sz && candidates[temp]==candidates[x])temp++;
            x=temp-1;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        helper(candidates,target,curr,0,candidates.size());
        return soln;
    }
};