class Solution {
    bool check(string s,bool issecword){
        int n=s.length();
        if(issecword){
            if(n>0&&s[n-1]=='0')return 0;
        }
        else{
            if(n>1&&s[0]=='0')return 0;
        }
        return 1;
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string>res;
        int n=s.length();
        s=s.substr(1,s.length()-2);
        for(int i=1;i<s.length();i++){
            string s1=s.substr(0,i);
            string s2=s.substr(i);
            // cout<<s1<<" "<<s2<<endl<<endl;
            vector<string>res1,res2;
            if(check(s1,false))res1.push_back(s1);
            if(check(s2,false))res2.push_back(s2);
            for(int j=1;j<s1.length();j++){
                string first=s1.substr(0,j);
                string second=s1.substr(j);
                if(check(first,false)&&check(second,true))res1.push_back(first+'.'+second);
            }
            for(int j=1;j<s2.length();j++){
                string first=s2.substr(0,j);
                string second=s2.substr(j);
                // cout<<first<<" "<<second<<endl;
                if(check(first,false)&&check(second,true))res2.push_back(first+'.'+second);
            }
            for(auto left:res1){
                for(auto right:res2){
                    res.push_back("(" + left + ", "+ right +")");
                }
            }
        }
        return res;
    }
};