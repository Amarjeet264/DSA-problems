class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int>st;
        for(auto it:words){
            st[it]++;
        }
        int n=words.size();
        int cnt=0;
        for(auto it:st){
            int j=0;
            int k=0;
            string x=it.first;
            while(j<x.size()&&k<s.size()){
                if(x[j]==s[k]){
                    j++;
                    k++;
                }
                else{
                    k++;
                }
            }
            if(j==x.size()){
                cnt+=st[x];
            }
        }
        return cnt;
    }
};