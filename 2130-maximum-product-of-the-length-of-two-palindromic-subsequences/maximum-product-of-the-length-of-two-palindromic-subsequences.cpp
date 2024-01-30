class Solution {
    vector<vector<int>>vec;
    bool check(vector<int>&a,vector<int>&b){       
        for(int i=0;i<a.size();i++)
            for(int j=0;j<b.size();j++)
                if(a[i]==b[j]) return false;
        return true;
    }
    bool ispalin(string a){
        int i=0;
        int j=a.size()-1;
        while(i<j){
            if(a[i]!=a[j]){
                return false;
            }
            i++;
            j--;
        }
        return 1;
    }
    void pro(string &s,int i,vector<int>&dup,string &x){
        if(i>=s.length()){
            if(ispalin(x)){
                vec.push_back(dup);
            }
            return ;
        }
        pro(s,i+1,dup,x);
        x.push_back(s[i]);
        dup.push_back(i);
        pro(s,i+1,dup,x);
        dup.pop_back();
        x.pop_back();
    }
public:
    int maxProduct(string s) {
        vector<int>dup;
        string x="";
        pro(s,0,dup,x);
        int n=vec.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cal=(int)vec[i].size()*vec[j].size();
                if(cal<maxi)continue;
                bool flag=check(vec[i],vec[j]);
                if(flag){
                    if(maxi<cal){
                        maxi=cal;
                    }
                }
            }
        }
        return maxi;
    }
};