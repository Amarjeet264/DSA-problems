class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        int i=0;
        int j=0;
        string ans="";
        while(i<n&&j<m){
            if(word1[i]>word2[j]){
                ans+=word1[i];
                i++;
            }
            else if(word2[j]>word1[i]){
                ans+=word2[j];
                j++;
            }
            else{
                if(word1.substr(i,n)>word2.substr(j,m)){
                    ans+=word1[i];
                    i++;
                }
                else{
                    ans+=word2[j];
                    j++;
                }
            }
        }
        while(i<n){
            ans+=word1[i];
            i++;
        }
        while(j<m){
            ans+=word2[j];
            j++;
        }
        return ans;
    }
};