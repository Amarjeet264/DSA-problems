class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n=words.size();
        int cnt=0;
        unordered_map<int,int>ind;
        for(int i=0;i<n;i++){
            map<char,int>even;
            map<char,int>odd;
            for(int j=i;j<n;j++){
                if(ind.find(j)!=ind.end())continue;
                if(even.size()==0&&odd.size()==0){
                    // cout<<words[j]<<" "<<j<<endl;
                    for(int k=0;k<words[j].size();k++){
                        if(k%2==0){
                            even[words[j][k]]++;
                        }
                        else{
                            odd[words[j][k]]++;
                        }
                    }
                    ind[j]++;
                    cnt++;
                }
                else{
                    // for(auto it:mp){
                    //     cout<<it.first<<" "<<it.second<<endl;
                    // }
                    map<char,int>e;
                    map<char,int>o;
                    for(int k=0;k<words[j].size();k++){
                        // cout<<words[j]<<" ";
                        if(k%2==0){
                            e[words[j][k]]++;
                        }
                        else{
                            o[words[j][k]]++;
                        }
                    }
                    if(even==e&&odd==o){
                        ind[j]++;
                    }
                }
            }
            // cout<<endl;
        }
        return cnt;
    }
};