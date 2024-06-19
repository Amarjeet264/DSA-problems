class Solution {
    vector<vector<int>>ans;
    void comb(vector<int>&arr,int n,int target,int i,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=n){
            return ;
        }
        for(int j=i;j<n;j++){
            if(j>i&&arr[j]==arr[j-1]){
                continue;
            }
            // if(temp.size()==0||(temp.size()>0&&arr[j]>=temp.back())){
                else if(target>=arr[j]){
                    temp.push_back(arr[j]);
                    comb(arr,n,target-arr[j],j+1,temp);
                    temp.pop_back();
                }
            // }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int>temp;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        comb(arr,n,target,0,temp);
        return ans;
    }
};