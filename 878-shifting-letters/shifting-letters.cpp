class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        for(int i=n-2;i>=0;i--){
            shifts[i]%=26;
            shifts[i]+=shifts[i+1];
        }
        for(int i=0;i<n;i++){
            shifts[i]%=26;
        }
        for(int i=0;i<n;i++){
            if(s[i]+shifts[i]<='z'){
                s[i]=s[i]+shifts[i];
            }
            else{
                shifts[i]=shifts[i]-('z'-s[i]);
                if(shifts[i]==0){
                    s[i]='z';
                }
                else{
                    s[i]='a';
                    shifts[i]--;
                    if(shifts[i]>0){
                        s[i]=s[i]+shifts[i];
                        shifts[i]=0;
                    }
                }
            }
        }
        return s;
    }
};