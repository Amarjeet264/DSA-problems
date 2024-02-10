class Solution {
public:
    int minNumberOfFrogs(string croak) {
        int n=croak.size();
        
        vector<string>v(n+1,"");
        
        map<char,int>mp;
        
        for(int i=0;i<n;i++){
            v[mp[croak[i]]]+=croak[i];
            // cout<<v[mp[croak[i]]]<<" ";
            mp[croak[i]]++;
        }
        for(auto it:v){
            if(it.size()>0&&it!="croak"){
                return -1;
            }
        }
        int maxi=0;
        int c=0;
        int k=0;
        for(int i=0;i<n;i++){
            if(croak[i]=='c'){
                c++;
            }
            else if(croak[i]=='k'){
                c--;
            }
            maxi=max(maxi,c);
        }
        return maxi;
    }
};