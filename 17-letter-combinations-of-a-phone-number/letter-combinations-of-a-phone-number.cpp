
class Solution {
    vector<string> ans;
    void find(int i,string s, string &temp, unordered_map<int,vector<char>>&m){
        if(i==s.size()){
            if(temp.size()!=0)
            ans.push_back(temp);
            return ;
        }
        int num=s[i]-'0';
        for(auto it:m[num]){
            temp.push_back(it);
            find(i+1,s,temp,m);
            temp.pop_back();
        }
    }
    public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<char>>m;
        char ch='a';
        int cnt=0;
        int i=2;
        while(i<=9){
            m[i].push_back(ch);
            ch++;
            cnt++;
            if(i!=7 && i!=9 && cnt==3){
                cnt = 0;
                i++;
            }
            if(i==7 || i==9){
                if(cnt==4){
                    cnt = 0;
                    i++;
                }
            }
        }
        string temp="";
        find(0,digits,temp,m);
        return ans;
    }
};