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
            if(target>=arr[j]){
                temp.push_back(arr[j]);
                comb(arr,n,target-arr[j],j,temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int>temp;
        int n=arr.size();
        comb(arr,n,target,0,temp);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};