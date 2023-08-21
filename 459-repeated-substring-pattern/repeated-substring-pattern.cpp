class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       string temp = s+s;
       return temp.substr(1, temp.length()-2).find(s)!=-1;
    }
};