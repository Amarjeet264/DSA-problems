class Solution {
public:
    int numTeams(vector<int>&arr) {
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]<arr[j]&&arr[j]<arr[k]){
                        cnt++;
                    }
                    else if(arr[i]>arr[j]&&arr[j]>arr[k]){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};