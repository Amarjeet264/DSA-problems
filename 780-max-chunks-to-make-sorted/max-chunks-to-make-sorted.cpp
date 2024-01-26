class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>vis(11,0);
        int ele=0;
        int cnt=0;
        int maxele=0;
        for(int i=0;i<arr.size();i++){
            vis[arr[i]]=1;
            if(arr[i]==ele){
                bool ha=1;
                for(int j=0;j<=maxele;j++){
                    if(vis[j]==0){
                        ha=0;
                        ele=j;
                        break;
                    }
                }
                if(ha){
                    cnt++;
                    for(int j=0;j<=10;j++){
                        if(vis[j]==0){
                            ele=j;
                            maxele=-1;
                            break;
                        }
                    }
                }
            }
            maxele=max(maxele,arr[i]);
            // cout<<ele<<" ";
        }
        return cnt;
    }
};