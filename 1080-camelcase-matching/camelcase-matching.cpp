class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            string s=queries[i];
            int lastidx=-1;
            for(int j=s.length()-1;j>=0;j--){
                if(isupper(s[j])){
                    lastidx=j;
                    break;
                }
            }
            int j=0;
            int k=0;
            while(j<s.size()&&k<pattern.size()){
                if(s[j]==pattern[k]){
                    j++;
                    k++;
                }
                else{
                    if(islower(s[j]))j++;
                    else break;
                }
            }
            if(j>lastidx&&k==pattern.size()){
                ans[i]=1;
            }
        }
        return ans;
    }
};