class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int cnt=0;
        vector<pair<int,pair<string,string>>>vec;
        for(int i=0;i<sources.size();i++){
            vec.push_back({indices[i],{sources[i],targets[i]}});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<indices.size();i++){
            int idx=vec[i].first;
            string x=vec[i].second.first;
            if(idx+cnt+x.length()>s.size()){
                continue;
            }
            string sub=s.substr(idx+cnt,x.length());
            string first=s.substr(0,idx+cnt);
            string last=s.substr(idx+cnt+x.length(),s.length());
            // cout<<sub<<" "<<first<<" "<<last<<endl;
            if(sub==x){
                // cout<<i<<" ";
                string tar=vec[i].second.second;
                s=first+tar+last;
                cnt+=(tar.size()-x.size());
            }
            // cout<<s<<endl;
        }
        return s;
    }
};