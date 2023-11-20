class Solution {
    
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int gt=0;
        int pt=0;
        int mt=0;
        int count=0;
        int n=garbage.size();
        int m=travel.size();
        int ans=0;
        ans=garbage[0].length();
        // cout<<ans<<" ";
        int piche=0;
        bool nhi=true;
        string s="";
        for(int i=0;i<m;i++){
            s=garbage[i+1];
            int g=0;
            nhi=true;
            for(int j=0;j<s.length();j++){
                if(s[j]=='G'){
                    if(g==0){
                        cout<<i<<" ";
                        g=g+piche+travel[i];
                    }
                    nhi=false;
                    g++;
                }
            }
            ans+=g;
            if(nhi==true){
                piche+=travel[i];
            }
            else{
                piche=0;
            }
        }
        cout<<ans<<" ";
        nhi=true;
        piche=0;
        for(int i=0;i<m;i++){
            s=garbage[i+1];
            int g=0;
            nhi=true;
            for(int j=0;j<s.length();j++){
                if(s[j]=='M'){
                    if(g==0){
                        g+=travel[i]+piche;
                    }
                    nhi=false;
                    g++;
                }
            }
            ans+=g;
            if(nhi==true){
                piche+=travel[i];
            }
            else{
                piche=0;
            }
        }
        cout<<ans<<" ";
        piche=0;
        nhi=true;
        for(int i=0;i<m;i++){
            s=garbage[i+1];
            int g=0;
            nhi=true;
            for(int j=0;j<s.length();j++){
                if(s[j]=='P'){
                    if(g==0){
                        g+=travel[i]+piche;
                    }
                    nhi=false;
                    g++;
                }
            }
            ans+=g;
            if(nhi==true){
                piche+=travel[i];
            }
            else{
                piche=0;
            }
        }
        return ans;
    }
};