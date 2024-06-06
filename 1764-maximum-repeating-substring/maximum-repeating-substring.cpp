class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int maxi=0;
        for(int j=0;j<sequence.size();j++){
            int i=j;
            int cnt=0;
            while(i<sequence.size()){
                if(sequence.substr(i,word.size())==word){
                    cnt++;
                    i=i+word.size();
                    // i++;
                }
                else{
                    // i++;
                    break;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};