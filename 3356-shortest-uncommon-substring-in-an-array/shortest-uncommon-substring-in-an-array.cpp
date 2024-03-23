class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string>ans;
        for(int i=0;i<arr.size();i++){
            string s=arr[i];
            string final="";
            for(int ori=0;ori<s.size();ori++){
                string orisub="";
                for(int x=ori;x<s.size();x++){
                    orisub+=s[x];
                    cout<<orisub<<" ";
                    bool can=1;
                    for(int j=0;j<arr.size();j++){
                        if(j==i)continue;
                        if(arr[j].find(orisub) != std::string::npos){
                            // cout<<j<<" ";
                            can=0;
                            break;
                        }
                        // else{
                        //     break;
                        // }
                    }
                    if(can==0){
                        continue;
                    }
                    if(final==""){
                        final=orisub;
                    }
                    else{
                        if(final.size()>orisub.size()){
                            final=orisub;
                        }
                        else if(final.size()==orisub.size()){
                            final=min(final,orisub);
                        }
                    }
                    // cout<<"iuhyghtgrfcgvh"<<endl;
                }
            }
            ans.push_back(final);
            // cout<<endl;
        }
        return ans;
    }
};