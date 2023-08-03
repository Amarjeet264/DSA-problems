
class Solution {
    void find(string digits,string s[],int i,vector<string>&ans,string &dup){
        if(i>=digits.length()){
            ans.push_back(dup);
            return;
        }
        int num=digits[i]-'0';
        cout<<num<<" ";
        string atnum=s[num];
        for(int j=0;j<atnum.length();j++){
            dup.push_back(atnum[j]);
            find(digits,s,i+1,ans,dup);
            dup.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
       string s[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       if(digits.length()==0){
           return {};
       }
       vector<string>ans;
       string dup="";
       find(digits,s,0,ans,dup);
       return ans;
    }
};