class Solution {
public:
    int maxDepth(string s) {
        int maxi=-1;
        int n=s.length();
        int open=0;
        int close=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                open--;
            }
            maxi=max(maxi,open);
        }
        return maxi;
    }
};