class Solution {
public:
    int captureForts(vector<int>& forts) {
        int maxi=0;
        int cnt=0;
        int j=0;
        // cout<<j<<endl;
        while(j<forts.size()&&forts[j]==0){
            j++;
        }
        while(j<forts.size()){
            if(forts[j]==1){
                int idx=j;
                while(j<forts.size()&&forts[j]==1){
                    // if(j==2)cout<<j<<" ";
                    j++;
                }
                idx=j;
                while(j<forts.size()&&forts[j]!=-1){
                    // if(j==3)cout<<j<<endl;
                    j++;
                    if(j<forts.size()&&forts[j]==1){
                        break;
                    }
                }
                if(j<forts.size()&&forts[j]==-1){
                    maxi=max(maxi,j-idx);
                }
                // cout<<j<<" ";
            }
            else if(forts[j]==-1){
                int idx=j;
                while(j<forts.size()&&forts[j]==-1){
                    j++;
                }
                idx=j;
                while(j<forts.size()&&forts[j]!=1){
                    j++;
                    if(j<forts.size()&&forts[j]==-1){
                        break;
                    }
                }
                if(j<forts.size()&&forts[j]==1){
                    maxi=max(maxi,j-idx);
                }
                // cout<<j<<" ";
            }
        }
        return maxi;
    }
};