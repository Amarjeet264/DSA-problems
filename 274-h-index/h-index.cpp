class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int>issejyadakitne(n+1,0);
        for(int i=0;i<citations.size();i++){
            if(citations[i]>n){
                issejyadakitne[n]+=1;
            }
            else{
                issejyadakitne[citations[i]]++;
            }
        }
        int sum=0;
        for(int i=n;i>=0;i--){
            sum+=issejyadakitne[i];
            if(sum>=i){
                return i;
            }
        }
        return -1;
    }
};