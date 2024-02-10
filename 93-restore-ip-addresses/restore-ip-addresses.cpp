class Solution {
    vector<string>ans;
    void call(string s,int i,string &final,int cnt){
        if(cnt>4){
            return;
        }
        // cout<<cnt<<" ";
        if(i>=s.length()){
            // cout<<cnt<<" "<<final<<endl;
            final.pop_back();
            if(cnt==4)ans.push_back(final);
            final+='.';
            return;
        }
        string dup="";
        for(int j=i;j<s.length();j++){
            if(j-i<3){
                dup+=s[j];
                if(stoi(dup)>255||(dup.size()>1&&dup[0]=='0'))return;
                final+=dup;
                final+='.';
                call(s,j+1,final,cnt+1);
                final.pop_back();
                int x=dup.size();
                while(x--){
                    final.pop_back();
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int cnt=0;
        string final="";
        call(s,0,final,cnt);
        return ans;
    }
};