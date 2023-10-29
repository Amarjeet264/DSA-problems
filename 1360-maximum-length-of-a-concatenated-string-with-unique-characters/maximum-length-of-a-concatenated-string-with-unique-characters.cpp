class Solution {
    bool poss(vector<int>&taken,string s){
        vector<int>abhi(26,0);
        for(int i=0;i<s.length();i++){
            if(abhi[s[i]-'a']==1){
                return false;
            }
            if(taken[s[i]-'a']==1){
                return false;
            }
            abhi[s[i]-'a']=1;
        }
        return true;
    }
    int leng(int i,vector<string>&arr,vector<int>taken,int len){
        if(i>=arr.size()){
            return len;
        }
        string ab=arr[i];
        if(poss(taken,ab)==false){
            return leng(i+1,arr,taken,len);
        }
        else{
            for(int j=0;j<ab.size();j++){
                taken[ab[j]-'a']=1;
            }
            len+=ab.size();
            int lele=leng(i+1,arr,taken,len);
            for(int j=0;j<ab.size();j++){
                taken[ab[j]-'a']=0;
            }
            len-=ab.size();
            int mtle=leng(i+1,arr,taken,len);
            return max(lele,mtle);
        }
    }
public:
    int maxLength(vector<string>& arr) {
      vector<int>taken(26,0);
      return leng(0,arr,taken,0);  
    }
};