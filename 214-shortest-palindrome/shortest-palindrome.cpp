class Solution {
public:
    string shortestPalindrome(string s) {
        string str=s;
        reverse(str.begin(),str.end());
        s+='#';
        s+=str;
        reverse(str.begin(),str.end());
        int i=0;
        int j=1;
        vector<int>vis(s.length(),0);
        while(j<s.length()){
            if(s[i]==s[j]){
                vis[j]=i+1;
                i++;
                j++;
            }
            else{
                if(i>0){
                    i=vis[i-1];
                }
                else{
                    vis[j]=0;
                    j++;
                }
            }
        }
        cout<<str.substr(0,i)<<endl;
        int count=str.length()-i;
        string temp="";
        j=str.length()-1;
        for(int i=0;i<count;i++)
        {
            temp+=str[j];
            j--;
        }
        return temp+str;
    }
};