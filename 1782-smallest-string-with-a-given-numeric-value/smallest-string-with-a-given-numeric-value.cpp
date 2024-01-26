class Solution {
public:
    string getSmallestString(int n, int k) {
        unordered_map<int,char>mp;
        int x=1;
        for(char ch='a';ch<='z';ch++){
            mp[x++]=ch;
        }
        int score=0;
        string s="";
        while(k<n*26){
            s+='a';
            k-=1;
            n-=1;
        }
        if(s.size()>0){
            n+=1;
            k+=1;
            s.pop_back();
        }
        cout<<k<<" "<<n<<" ";
        // // cout<<s<<" ";
        int zc=k/26;
        k=k-26*zc;
        if(k)s+=mp[k];
        for(int i=0;i<zc;i++){
            s+='z';
        }
        return s;
    }
};