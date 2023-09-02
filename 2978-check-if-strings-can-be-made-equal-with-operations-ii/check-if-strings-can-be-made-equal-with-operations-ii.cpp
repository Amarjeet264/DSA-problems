class Solution {
public:
    bool checkStrings(string s1, string s2) {
        map<char,int>m1;
        map<char,int>m2;
        for(int i=0;i<s1.length();i++){
            if(i%2){
               m1[s1[i]]++;
               m1[s2[i]]++;
            }
            else{
                m2[s1[i]]++;
                m2[s2[i]]++;
            }
        }
        for(auto i : m1){
            if(i.second%2) return false;
        }
        for(auto i : m2){
            if(i.second%2) return false;
        }
        return true;
    }
};