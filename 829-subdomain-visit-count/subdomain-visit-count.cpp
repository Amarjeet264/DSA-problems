class Solution {
public:
    vector<string> subdomainVisits(vector<string>&domain) {
        unordered_map<string,int>mp;
        for(int i=0;i<domain.size();i++){
            int x=0;
            bool first=false;
            string s="";
            int k=0;
            while(domain[i][k]!=' '){
                x=x*10+(domain[i][k]-'0');
                k++;
            }
            // cout<<x<<" ";
            for(int j=domain[i].size()-1;j>=k;j--){
                if(domain[i][j]=='.'){
                    reverse(s.begin(),s.end());
                    mp[s]+=x;
                    // s="";
                    reverse(s.begin(),s.end());
                    s+='.';
                }
                else{
                    if(j==k){
                        reverse(s.begin(),s.end());
                        mp[s]+=x;
                    }
                    s+=domain[i][j];
                }
                // cout<<s<<endl;
            }
        }
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        vector<string>ans;
        for(int i=0;i<domain.size();i++){
            int x=0;
            bool first=false;
            string s="";
            string ind="";
            for(int j=domain[i].size()-1;j>=0;j--){
                if(domain[i][j]=='.'||domain[i][j]==' '){
                    // reverse(ind.begin(),ind.end());
                    reverse(s.begin(),s.end());
                    // cout<<s<<" "<<ind<<endl;
                    if(mp.find(s)!=mp.end()){
                        ans.push_back(to_string(mp[s])+' '+ s );
                        mp.erase(s);
                    }
                    // ind="";
                    reverse(s.begin(),s.end());
                    s+=domain[i][j];
                }
                else{
                    s+=domain[i][j];
                    // ind+=domain[i][j];
                }
            }
        }
        return ans;
    }
};