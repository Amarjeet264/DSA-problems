class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       string temp = s+s;
       string cont=temp.substr(1, temp.length()-2);
       return cont.find(s)!=-1;
    }
};