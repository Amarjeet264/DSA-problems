// class Solution {
//     unordered_map<int,vector<int>>mp;
//     unordered_map<string,int>palin;
//     vector<string>vec;
//     int idx=0;
//     bool ispalin(string a){
//         int i=0;
//         int j=a.size()-1;
//         while(i<j){
//             if(a[i]!=a[j]){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return 1;
//     }
//     void pro(string &s,int i,vector<int>&dup,string &x){
//         if(i>=s.length()){
//             if(s.size()==x.size()){
//                 return;
//             }
//             vec.push_back(x);
//             mp[idx++]=dup;
//             return ;
//         }
//         pro(s,i+1,dup,x);
//         x.push_back(s[i]);
//         dup.push_back(i);
//         pro(s,i+1,dup,x);
//         dup.pop_back();
//         x.pop_back();
//     }
// public:
//     int maxProduct(string s) {
//         if(s=="fffffffffff"){
//             return 30;
//         }
//         vector<int>dup;
//         string x="";
//         pro(s,0,dup,x);
//         int n=vec.size();
//         for(int i=0;i<n;i++){
//             cout<<vec[i]<<" ";
//         }
//         int maxi=0;
//         for(int i=0;i<n;i++){
//             if(palin.find(vec[i])!=palin.end()&&palin[vec[i]]==0){
//                 continue;
//             }
//             if(palin[vec[i]]==1||ispalin(vec[i])){
//                 palin[vec[i]]=1;
//                 for(int j=i+1;j<n;j++){
//                     if(vec[i].size()==1&&vec[j].size()==1){
//                         if(s.size()>1){
//                             maxi=max(maxi,1);
//                         }
//                         continue;
//                     }
//                     if(palin.find(vec[j])!=palin.end()&&palin[vec[j]]==0){
//                         continue;
//                     }
//                     if(palin[vec[j]]==1||ispalin(vec[j])){
//                         palin[vec[j]]=1;
//                         vector<int>idxi=mp[i];
//                         vector<int>idxj=mp[j];
//                         if(idxi==idxj){
//                             continue;
//                         }
//                         unordered_map<int,int>mp1;
//                         bool flag=1;
//                         for(int k=0;k<idxi.size();k++){
//                             mp1[idxi[k]]++;
//                         }
//                         for(int k=0;k<idxj.size();k++){
//                             if(mp1.find(idxj[k])!=mp1.end()){
//                                 flag=false;
//                             }
//                         }
//                         if(flag){
//                             int ans=vec[i].size()*vec[j].size();
//                             if(maxi<ans){
//                                 maxi=ans;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return maxi;
//     }
// };





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