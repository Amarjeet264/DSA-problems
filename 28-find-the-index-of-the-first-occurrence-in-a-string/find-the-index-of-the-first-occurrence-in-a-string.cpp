class Solution {
public:
    int strStr(string h, string n) {
        int i=0;
        int j=0;
        int k=0;
        while(j<h.size()){
            if(h[j]==n[k]){
                if(n.size()==j-i+1){
                    return i;
                }
                j++;
                k++;
            }
            else{
                k=0;
                j=i+1;
                i=j;
            }
        }
        return -1;
    }
};