class Solution {
public:
    string decodeCiphertext(string enco, int rows) {
        if(enco.size()==0)return "";
        string s="";
        int n=enco.size();
        int col=n/rows;
        for(int i=0;i<col;i++){
            int j=i;
            while(j<n){
                s+=enco[j];
                j=j+col+1;
            }
        }
        while(s.back()==' '){
            s.pop_back();
        }
        return s;
    }
};